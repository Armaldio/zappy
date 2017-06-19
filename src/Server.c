/*
** Server.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:21:42 2017 Martin Alais
** Last update Mon Jun 19 19:23:09 2017 Martin Alais
*/

#include "Server.h"
#include "Player.h"
#include "Socket.h"
#include "zappy.h"

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
		printf("New player connected with fd: %d and id: %d\n",
		fd, server->list_player->id);
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

void do_it(t_Player *tmp, t_Server *server, char *data_recv, int a)
{
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

void check_data_player(t_Server *server)
{
	int a;
	char data_recv[4096];
	struct timeval tv;
	t_Player *tmp;
	fd_set rfds;

	tmp = server->list_player;
	memset(data_recv, '\0', 4096);
	while (tmp != NULL)
	{
		FD_ZERO(&rfds);
		FD_SET(tmp->fd, &rfds);
		tv.tv_sec = 0;
		tv.tv_usec = 300;
		a = select(tmp->fd + 1, &rfds, NULL, NULL, &tv);
		if (a != 0 && tmp->is_connected == true)
		{
			a = recv(tmp->fd, data_recv, 4095, MSG_DONTWAIT);
			do_it(tmp, server, data_recv, a);
			memset(data_recv, '\0', 4096);
		}
		tmp = tmp->next;
	}
}

void check_new_player(t_Server *server)
{
	int a;
	set_socket_statue(server->socket->fd, 0);
	a = accept(server->socket->fd,
		(struct sockaddr *)&server->socket->s_in_accept,
		&server->socket->s_in_size_accept);
	if (a != -1)
		add_player(server, a);
	set_socket_statue(server->socket->fd, 1);
}
