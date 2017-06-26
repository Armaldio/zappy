/*
** Server.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:21:42 2017 Martin Alais
** Last update Mon Jun 26 16:26:06 2017 Martin Alais
*/

#include "Server.h"
#include "Player.h"
#include "Socket.h"
#include "zappy.h"
#include "Event.h"

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

  end_game(server);
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

int get_new_id(t_Server *server)
{
	int a;
	t_Player *tmp;
	a = 0;

	tmp = server->list_player;
	while (tmp)
	{
		if (tmp->isEgg == false)
			a = tmp->id;
		tmp = tmp->next;
	}
	return (a);
}

void eggs_connection_message(int a, t_Player *p)
{
	send_message(a, "WELCOME\n");
  printf("Linking connection to player %d\n", p->id);
	send_message(p->fd, "ok\n");
}

void check_new_player(t_Server *server)
{
  int a;

  set_socket_statue(server->socket->fd, 0);
  a = accept(server->socket->fd,
	     (struct sockaddr *)&server->socket->s_in_accept,
	     &server->socket->s_in_size_accept);
set_socket_statue(server->socket->fd, 1);
  t_Player *p = get_First_Player_Available(server->list_player);
  if (a != -1)
    {
      if (p != NULL)
	{
		eggs_connection_message(a, p);
	  p->is_connected = true;
	  p->isEgg = false;
	  p->controlled = true;
	  p->fd = a;
	  event_conection_for_eggs(server, p);
	  p->id = get_new_id(server);
	  event_new_player(server, p);
	  return ;
	}
      else
	  add_undefined(a, server);
    }
}
