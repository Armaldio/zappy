/*
** Server.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:21:42 2017 Martin Alais
** Last update Wed Jun 21 13:50:38 2017 Quentin Goinaud
*/

#include "Server.h"
#include "Player.h"
#include "Socket.h"
#include "zappy.h"

void add_to_line(t_Player *tmp, char *data_recv, int a, t_Server *server)
{
	if (a == 0)
	{
		tmp->is_connected = false;
		printf("Player with id %d disconected\n", tmp->id);
		my_delete_player(server, tmp->id);
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
			add_to_line(tmp, data_recv, a, server);
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
		my_add_player(server, a);
	set_socket_statue(server->socket->fd, 1);
}
