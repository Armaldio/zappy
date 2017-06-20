/*
** server2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:21:28 2017 Martin Alais
** Last update Tue Jun 20 10:39:52 2017 loic1.doyen@epitech.eu
*/

#include "Server.h"
#include "Player.h"
#include "Socket.h"
#include "zappy.h"

void basic_init_server(t_Server *server)
{
	server->list_player = my_malloc(sizeof(t_Player));
	server->socket = my_malloc(sizeof(t_Connection));
	server->world = my_malloc(sizeof(t_World));
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
	server->f = 100;
	server->time = 0;
	server->fake_time = -1;
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
				return (res);
			res.y += 1;
		}
		res.x += 1;
	}
	printf("[Error] no more space for spawn\n");
	res.x = -1;
	res.y = -1;
	return (res);
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
