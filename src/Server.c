/*
** Server.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:21:42 2017 Martin Alais
** Last update Tue Jun 20 13:53:13 2017 hamza hammouche
*/

#include "Server.h"
#include "Player.h"
#include "Socket.h"
#include "zappy.h"

void add_player(t_Server *server, int fd)
{
  add_new_player(server, fd);
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
			do_it(tmp, server, data_recv, a);
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
