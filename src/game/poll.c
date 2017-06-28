/*
** poll.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/game/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 14:29:52 2017 Martin Alais
** Last update Tue Jun 27 18:29:14 2017 hamza hammouche
*/

#include <poll.h>
#include "zappy.h"

int poll_nbr_fd(t_Server *server)
{
	int nbr;
	t_graphic *tmp;
	t_undefined *tmp2;

	nbr = 0;
	tmp = server->list_graphic;
	tmp2 = server->list_undefined;

	while (tmp)
	{
		nbr += 1;
		tmp = tmp->next;
	}
	while (tmp2)
	{
		nbr += 1;
		tmp2 = tmp2->next;
	}
	nbr += poll_nbr_fd2(server);
	return (nbr);
}

void complete_struct(t_Server *server, struct pollfd *poll_fd)
{
	t_graphic *tmp;
	t_undefined *tmp2;

	int nbr;

	nbr = 0;
	tmp = server->list_graphic;
	tmp2 = server->list_undefined;
	while (tmp)
	{
		poll_fd[nbr].fd = tmp->fd;
		poll_fd[nbr].events = POLLIN;
		nbr += 1;
		tmp = tmp->next;
	}
	while (tmp2)
	{
		poll_fd[nbr].fd = tmp2->fd;
		poll_fd[nbr].events = POLLIN;
		nbr += 1;
		tmp2 = tmp2->next;
	}
	complete_struct2(server, poll_fd, nbr);
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
			a = recv(tmp3->fd, data_recv, 4095, MSG_DONTWAIT);
			add_to_line(tmp3, data_recv, a, server);
			return ;
		}
		tmp3 = tmp3->next;
	}
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
	poll(poll_fd, max, 500);
	while (nbr < max)
	{
		if (poll_fd[nbr].revents == POLLIN)
			send_to_struct(server, poll_fd[nbr].fd);
		nbr += 1;
	}
}
