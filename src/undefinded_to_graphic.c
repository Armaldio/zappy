/*
** undefinded_to_graphic.c for zappy in /home/hammouche/Documents/PSU_2016/zappy/src/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Sat Jun 24 12:42:19 2017 hamza hammouche
** Last update Sat Jun 24 12:43:00 2017 hamza hammouche
*/

#include "zappy.h"
#include "Graphic.h"

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
