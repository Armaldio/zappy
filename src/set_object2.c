/*
** set_object2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 12:06:35 2017 Martin Alais
** Last update Fri Jun 23 15:36:54 2017 Martin Alais
*/

#include "zappy.h"

void send_message_item(t_Player *player, int id, int nb)
{
	char buffer[512];

  sprintf(buffer, "pdr %d %d\n", id, nb);
  stok_answer(player, buffer);
}

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
		server->isGraphic == true ? send_message_item(tmp, tmp->id, 6) :
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
		server->isGraphic == true ? send_message_item(tmp, tmp->id, 0) :
	      stok_answer(tmp, "ok\n");
	}
	else
		stok_answer(tmp, "ko\n");
}
