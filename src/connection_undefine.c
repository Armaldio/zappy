/*
** connection_type.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Fri Jun 23 17:45:21 2017 Martin Alais
** Last update Fri Jun 23 19:50:02 2017 Martin Alais
*/

#include "zappy.h"
#include "Graphic.h"

void init_undefine(t_undefined *new, int fd, int id)
{
	new->fd = fd;
	new->id = id;
	new->next = NULL;
	printf("Undefine %d created\n", new->id);
	send_message(fd, "WELCOME\n");
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

t_Player *get_last_player(t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void undefined_to_player(t_Server *server, t_undefined *undefine, t_team *team)
{

	t_Player *tmp;
	my_add_player(server, undefine->fd);
	tmp = get_last_player(server);
	printf("Undefine %d become Player %d !\n", undefine->id, tmp->id);
	get_player_team(tmp, team->name, server);
	delete_undefine(server, undefine->id);
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
