/*
** set_object2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 12:06:35 2017 Martin Alais
** Last update Sat Jun 24 16:03:29 2017 Martin Alais
*/

#include "zappy.h"
#include "Event.h"

void set_thystane(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->inventaire->thystane >= 1)
	{
		server->world->map[tmp->pos.x][tmp->pos.y]->thystane += 1;
		tmp->inventaire->thystane -= 1;
		event_drop(server, tmp, 6);
		stok_answer(tmp, "ok\n");
	}
	else
		stok_answer(tmp, "ko\n");
}

void set_food(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->inventaire->food >= 1)
	{
		server->world->map[tmp->pos.x][tmp->pos.y]->food += 1;
		tmp->inventaire->food -= 1;
		event_drop(server, tmp, 0);
		stok_answer(tmp, "ok\n");
	}
	else
		stok_answer(tmp, "ko\n");
}
