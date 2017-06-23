/*
** take_object2.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Tue Jun 20 10:03:35 2017 loic1.doyen@epitech.eu
** Last update Fri Jun 23 16:29:02 2017 Martin Alais
*/

#include "zappy.h"

void send_message_take(t_Player *player, int id, int nb)
{
	char buffer[512];

  sprintf(buffer, "pgt %d %d\n", id, nb);
  stok_answer(player, buffer);
}

void take_thystane(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (server->world->map[tmp->pos.x][tmp->pos.y]->thystane >= 1)
	{
		server->world->map[tmp->pos.x][tmp->pos.y]->thystane -= 1;
		tmp->inventaire->thystane += 1;
		tmp->isGraphic == true ? send_message_take(tmp, tmp->id, 6) :
	      stok_answer(tmp, "ok\n");
	}
	else
		stok_answer(tmp, "ko\n");
}

void take_food(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (server->world->map[tmp->pos.x][tmp->pos.y]->food >= 1)
	{
		server->world->map[tmp->pos.x][tmp->pos.y]->food -= 1;
		tmp->inventaire->food += 1;
		tmp->isGraphic == true ? send_message_take(tmp, tmp->id, 0) :
	      stok_answer(tmp, "ok\n");
	}
	else
		stok_answer(tmp, "ko\n");
}
