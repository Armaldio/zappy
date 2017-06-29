/*
** poll.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/game/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 14:29:52 2017 Martin Alais
** Last update Thu Jun 29 14:16:35 2017 Martin Alais
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

void print_tab(char **tab)
{
	int a;

	a = 0;
	printf("Start print tab\n");
	while (tab[a])
	{
		printf("%s", tab[a]);
		a += 1;
	}
	printf("End print tab\n");
}

char **str_to_word_tab(char *str, char del)
{
	char **res;
	int nbr_ite;
	int a;
	int b;
	int c;

	a = 0;
	nbr_ite = get_nbr_del(str, del);
	res = my_malloc(sizeof(char *) * (nbr_ite + 1));
	while (a < nbr_ite)
	{
		res[a] = my_malloc(sizeof(char) * (strlen(str) + 5));
		memset(res[a], '\0', strlen(str) + 5);
		a += 1;
	}
	res[a] = NULL;
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
	};
	print_tab(res);
	return (res);
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
	char **data;
	int a;
	int b;

	b = 0;
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
			data = str_to_word_tab(data_recv, '\n');
			while (data[b])
			{
				if (data[b][0] != '\0')
					add_to_line(tmp3, data[b], a, server);
				b += 1;
			}
			free_tab(data);
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
	poll(poll_fd, max, 50);
	while (nbr < max)
	{
		if (poll_fd[nbr].revents == POLLIN)
			send_to_struct(server, poll_fd[nbr].fd);
		nbr += 1;
	}
}
