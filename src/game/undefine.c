/*
** undefine.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/game/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:38:41 2017 Martin Alais
** Last update Fri Jun 30 16:30:16 2017 Martin Alais
*/

#include "zappy.h"
#include "Graphic.h"
#include "Event.h"
#include "unix_cbuffer.h"

void init_undefine(t_undefined *new, int fd, int id)
{
	new->fd = fd;
	new->id = id;
	new->read_buffer = ucbuffer_new(4096);
	new->write_buffer = ucbuffer_new(4096);
	new->next = NULL;
	printf("Undefine %d created\n", new->id);
	send_message_undefine(new, "WELCOME\n");
}

void add_undefined(int fd, t_Server *server)
{
	t_undefined *new;
	t_undefined *tmp;

	new = my_malloc(sizeof(t_undefined));
	tmp = server->list_undefined;
	if (server->list_undefined != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
	if (server->list_undefined == NULL)
	{
		init_undefine(new, fd, 1);
		server->list_undefined = new;
	}
	else
	{
		init_undefine(new, fd, tmp->id + 1);
		tmp->next = new;
	}
}

t_graphic *get_last_graphic(t_Server *server)
{
	t_graphic *tmp;

	tmp = server->list_graphic;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void undefined_to_graphic(t_Server *server, t_undefined *undefine)
{
	t_graphic *tmp;

	add_graphic(undefine->fd, server);
	tmp = get_last_graphic(server);
	printf("Undefine %d become Graphic %d !\n", undefine->id, tmp->id);
	commande_graphic(tmp, server, "");
	delete_undefine(server, undefine->id);
	send_all_player(server, tmp);
}

void delete_undefine(t_Server *server, int id)
{
	t_undefined *tmp;
	t_undefined *last;

	last = NULL;
	tmp = server->list_undefined;
	while (tmp)
	{
		if (tmp->id == id)
		{
			printf("Undefine with id %d deleted\n", tmp->id);
			if (last == NULL)
				server->list_undefined = tmp->next;
			else
				last->next = tmp->next;
			free(tmp);
			return;
		}
		last = tmp;
		tmp = tmp->next;
	}
}
