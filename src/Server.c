#include "Server.h"
#include "Player.h"
#include "Socket.h"
#include "zappy.h"

void basic_init_server(t_Server *server)
{
	server->list_player = malloc(sizeof(t_Player));
	server->socket = malloc(sizeof(t_Connection));
	server->world = malloc(sizeof(t_World));
	basic_init_socket(server->socket);
	basic_init_world(server->world);
}

void init_inventaire(t_Player *player)
{
	player->inventaire = my_malloc(sizeof(t_Inventaire));
	player->inventaire->deraumere = 0;
	player->inventaire->linemate = 0;
	player->inventaire->mendiane = 0;
	player->inventaire->phiras = 0;
	player->inventaire->sibur = 0;
	player->inventaire->thystane = 0;
}

void init_server(t_Server *server)
{
	init_socket(server->socket);
	server->list_player = init_player();
	init_world(server->world);
	print_world(server->world);
	init_inventaire(server->list_player);
}

t_Position get_spaw_pos(t_Server *server)
{
	t_Position res;

	res.x = 0;
	while (res.x < server->world->height - 1)
	{
		res.y = 0;
		while (res.y < server->world->width - 1)
		{
			if (case_occupation(server->world, res.x, res.y) == false)
				return(res);
			res.y += 1;
		}
		res.x += 1;
	}
	printf("[Error] no more space for spawn\n");
	res.x = -1;
	res.y = -1;
	return(res);
}

void add_new_player(t_Server *server, int fd)
{
	t_Player *new;
	t_Player *tmp;
	t_Position spaw_pos;

	tmp = server->list_player;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new = malloc(sizeof(t_Player));
	new->fd = fd;
	new->id = server->list_player->id + 1;
	new->is_connected = true;
	new->gaze = UP;
	spaw_pos = get_spaw_pos(server);
	if (spaw_pos.x == -1 || spaw_pos.y == -1)
		send_message(fd, "KO\n");
	new->pos.x = spaw_pos.x;
	new->pos.y = spaw_pos.y;
	set_occupation(server->world, new->pos.x, new->pos.y, true);
	new->level = 1;
	init_inventaire(new);
	new->next = NULL;
	tmp->next = new;
	printf("New player connected with fd: %d and id: %d\n", new->fd, new->id);
	send_message(fd, "BIENVENUE\n");
}

void add_player(t_Server *server, int fd)
{
	if (server->list_player->fd == -1)
	{
		server->list_player->fd = fd;
		server->list_player->is_connected = true;
		server->list_player->gaze = UP;
		set_occupation(server->world, 0, 0, true);
		server->list_player->pos.x = 0;
		server->list_player->pos.y = 0;
		server->list_player->level = 1;
		printf("New player connected with fd: %d and id: %d\n", fd, server->list_player->id);
		send_message(fd, "BIENVENUE\n");
	}
	else
		add_new_player(server, fd);
}

void check_last(t_Server *server)
{
	int a;

	char data_recv[4096];
	struct timeval tv;
	fd_set rfds;

	memset(data_recv, '\0', 4096);
	FD_ZERO(&rfds);
	FD_SET(server->list_player->fd, &rfds);
	tv.tv_sec = 0;
	tv.tv_usec = 300;
	a = select(server->list_player->fd + 1, &rfds, NULL, NULL, &tv);
	if (a != 0 && server->list_player->is_connected == true)
	{
		a = recv(server->list_player->fd, data_recv, 4095, MSG_DONTWAIT);
		if (a == 0)
		{
			server->list_player->is_connected = false;
			printf("Player with id %d disconected\n", server->list_player->id);
		}
		else
			printf("%d: %s\n", server->list_player->id, data_recv);
	}
}

void check_data_player(t_Server *server)
{
	int a;
	char data_recv[4096];
	struct timeval tv;
	t_Player *tmp;
	fd_set rfds;

	tmp = server->list_player;
	memset(data_recv, '\0', 4096);
	while (tmp->next != NULL)
	{
		FD_ZERO(&rfds);
		FD_SET(tmp->fd, &rfds);
		tv.tv_sec = 0;
		tv.tv_usec = 300;
		a = select(tmp->fd + 1, &rfds, NULL, NULL, &tv);
		if (a != 0 && tmp->is_connected == true)
		{
			a = recv(tmp->fd, data_recv, 4095, MSG_DONTWAIT);
			if (a == 0)
			{
				tmp->is_connected = false;
				printf("Player with id %d disconected\n", tmp->id);
			}
			else
			{
				printf("%d: %s\n", tmp->id, data_recv);
				parser_commande(tmp->id, server, data_recv);
			}
			memset(data_recv, '\0', 4096);
		}
		tmp = tmp->next;
	}
	FD_ZERO(&rfds);
	FD_SET(tmp->fd, &rfds);
	tv.tv_sec = 0;
	tv.tv_usec = 300;
	a = select(tmp->fd + 1, &rfds, NULL, NULL, &tv);
	if (a != 0 && tmp->is_connected == true)
	{
		a = recv(tmp->fd, data_recv, 4095, MSG_DONTWAIT);
		if (a == 0)
		{
			tmp->is_connected = false;
			printf("Player with id %d disconected\n", tmp->id);
		}
		else
		{
			printf("%d: %s\n", tmp->id, data_recv);
			parser_commande(tmp->id, server, data_recv);
		}
	}
}

void check_new_player(t_Server *server)
{
	int a;
	set_socket_statue(server->socket->fd, 0);
	a = accept(server->socket->fd, (struct sockaddr *)&server->socket->s_in_accept, &server->socket->s_in_size_accept);
	if (a != -1)
		add_player(server, a);
	set_socket_statue(server->socket->fd, 1);
}
