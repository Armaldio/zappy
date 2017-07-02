/*
** poll4.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/game/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Fri Jun 30 15:43:39 2017 Martin Alais
** Last update Sun Jul  2 19:10:39 2017 Martin Alais
*/

#include "zappy.h"
#include "unix_cbuffer.h"

void complete_read_graphic(t_graphic *tmp3, char *data_recv, t_Server *server)
{
	int a;

	a = zappy_getline(tmp3->read_buffer, data_recv);
	strcat(data_recv, "\n");
	printf("%d: %s", tmp3->id, data_recv);
	graphic_parser(tmp3->id, server, data_recv);
	memset(data_recv, '\0', 4095);
	while (a > 0)
	{
		a = zappy_getline(tmp3->read_buffer, data_recv);
		if (a != 0)
		{
			strcat(data_recv, "\n");
			printf("%d: %s", tmp3->id, data_recv);
			graphic_parser(tmp3->id, server, data_recv);
			memset(data_recv, '\0', 4095);
		}
	}
}

void write_to_socket2(t_Server *server, int fd)
{
	t_graphic *graphic;

	graphic = server->list_graphic;
	while (graphic)
	{
		if (graphic->fd == fd)
		{
			zappy_ucbuffer_send(graphic->fd, graphic->write_buffer);
			return ;
		}
		graphic = graphic->next;
	}
}

void write_to_socket(t_Server *server, int fd)
{
	t_Player *player;
	t_undefined *undefine;

	player = server->list_player;
	while (player)
	{
		if (player->fd == fd)
		{
			zappy_ucbuffer_send(player->fd, player->write_buffer);
			return;
		}
		player = player->next;
	}
	undefine = server->list_undefined;
	while (undefine)
	{
		if (undefine->fd == fd)
		{
			zappy_ucbuffer_send(undefine->fd, undefine->write_buffer);
			return;
		}
		undefine = undefine->next;
	}
	write_to_socket2(server, fd);
}

void check_poll_data(struct pollfd *poll_fd, int nbr, t_Server *server)
{
	if (poll_fd[nbr].revents & POLLIN)
		send_to_struct(server, poll_fd[nbr].fd);
	if (poll_fd[nbr].revents & POLLOUT)
		write_to_socket(server, poll_fd[nbr].fd);
}
