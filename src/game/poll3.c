/*
** poll3.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/game/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 29 14:33:37 2017 Martin Alais
** Last update Thu Jun 29 14:34:54 2017 Martin Alais
*/

#include "zappy.h"
#include <poll.h>

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

int get_nbr_del(char *str, char del)
{
	int a;
	int nbr;

	nbr = 0;
	a = 0;
	while (str[a])
	{
		if (str[a] == del)
			nbr += 1;
		a += 1;
	}
	return (nbr);
}
