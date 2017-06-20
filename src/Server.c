/*
** Server.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:21:42 2017 Martin Alais
** Last update Tue Jun 20 13:54:35 2017 Martin Alais
*/

#include "Server.h"
#include "Player.h"
#include "Socket.h"
#include "zappy.h"

void add_player(t_Server *server, int fd)
{
  add_new_player(server, fd);
}

void add_to_line(t_Player *tmp, char *data_recv, int a)
{
	if (a == 0)
	{
		tmp->is_connected = false;
		printf("Player with id %d disconected\n", tmp->id);
	}
	else
	{
		printf("%d: %s", tmp->id, data_recv);
		add_data_in_line(tmp, data_recv);
	}
}

void check_data_player(t_Server *server)
{
	int a;
	char data_recv[4096];
	struct timeval tv;
	t_Player *tmp;
	fd_set rfds;

	tmp = server->list_player->next;
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
			add_to_line(tmp, data_recv, a);
			memset(data_recv, '\0', 4096);
		}
		tmp = delete_player(server, tmp);
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
