/*
** take_object2.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Tue Jun 20 10:03:35 2017 loic1.doyen@epitech.eu
** Last update Tue Jun 20 10:03:53 2017 loic1.doyen@epitech.eu
*/

#include "zappy.h"

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
		send_message(tmp->fd, "OK\n");
	}
	else
		send_message(tmp->fd, "KO\n");
}
