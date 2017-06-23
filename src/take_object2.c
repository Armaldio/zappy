/*
** take_object2.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Tue Jun 20 10:03:35 2017 loic1.doyen@epitech.eu
** Last update Fri Jun 23 15:04:38 2017 hamza hammouche
*/

#include "zappy.h"

void send_message_take(int fd, int id, int nb)
{
	char buffer[512];

  sprintf(buffer, "pgt %d %d\n", id, nb);
  send_message(fd, buffer);
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
		tmp->isGraphic == true ? send_message_take(tmp->fd, tmp->id, 6) :
	      send_message(tmp->fd, "ok\n");
	}
	else
		send_message(tmp->fd, "ko\n");
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
		tmp->isGraphic == true ? send_message_take(tmp->fd, tmp->id, 0) :
	      send_message(tmp->fd, "ok\n");
	}
	else
		send_message(tmp->fd, "ko\n");
}
