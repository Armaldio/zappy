/*
** poll.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/game/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 14:29:52 2017 Martin Alais
** Last update Fri Jun 30 15:23:34 2017 Martin Alais
*/

#include <poll.h>
#include "zappy.h"
#include "unix_cbuffer.h"

void str_tab_2(char **res, char *str, char del)
{
	int a;
	int b;
	int c;

	b = 0;
	a = 0;
	c = 0;
	while (str[a])
	{
		if (str[a] == del)
		{
			res[b][c] = '\n';
			res[b][c + 1] = '\0';
			c = 0;
			b += 1;
		}
		else
		{
			res[b][c] = str[a];
			c += 1;
		}
		a += 1;
	}
}

void free_tab(char **tab)
{
	int a;

	a = 0;
	while (tab[a])
	{
		free(tab[a]);
		a += 1;
	}
	free(tab);
}

void send_to_struct(t_Server *server, int fd)
{
	t_Player *tmp3;
	char data_recv[4095];
	int a;

	memset(data_recv, '\0', 4095);
	tmp3 = server->list_player;
	if (send_for_graphic(server, fd, data_recv) == true)
		return;
	if (send_for_undefine(server, fd, data_recv) == true)
		return ;
	while (tmp3)
	{
		if (tmp3->fd == fd && tmp3->controlled == true)
		{
			a = ucbuffer_fromfd(tmp3->fd, tmp3->read_buffer, 1024);
			if (a == 0)
				player_disconnected(tmp3, server);
			if (a <= 0)
				return ;
			ucbuffer_move(tmp3->read_buffer, &tmp3->read_buffer->tail, a);
			complete_read(tmp3, data_recv);
			return ;
		}
		tmp3 = tmp3->next;
	}
}

void free_poll_fd(struct pollfd *poll_fd)
{
  if (poll_fd != NULL)
    free(poll_fd);
}

void my_poll(t_Server *server)
{
	struct pollfd *poll_fd;
	int nbr;
	int max;
  int i;

  i = 0;
	max = poll_nbr_fd(server) + 1;
	nbr = 0;
	poll_fd = my_malloc(sizeof(struct pollfd) * max);
	while (i < max)
    {
      poll_fd[i].events = -1;
      poll_fd[i].fd = -1;
      poll_fd[i].revents = -1;
      i++;
    }
	complete_struct(server, poll_fd);
	poll(poll_fd, max, get_poll_timeout(server));
	while (nbr < max)
	{
		if (poll_fd[nbr].revents == POLLIN)
			send_to_struct(server, poll_fd[nbr].fd);
		nbr += 1;
	}
  free_poll_fd(poll_fd);
}
