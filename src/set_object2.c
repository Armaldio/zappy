/*
** set_object2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 12:06:35 2017 Martin Alais
** Last update Thu Jun 22 12:26:11 2017 Martin Alais
*/

#include "zappy.h"

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
		send_message(tmp->fd, "OK\n");
	}
	else
		send_message(tmp->fd, "KO\n");
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
		send_message(tmp->fd, "OK\n");
	}
	else
		send_message(tmp->fd, "KO\n");
}