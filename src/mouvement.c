/*
** mouvement.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Tue Jun 20 09:44:49 2017 loic1.doyen@epitech.eu
** Last update Fri Jun 23 15:45:56 2017 Martin Alais
*/

#include "zappy.h"
#include "mouvement.h"

void go_left(t_Server *server, int id, bool send)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->pos.x > 0)
		tmp->pos.x -= 1;
	else
		tmp->pos.x = server->world->height - 1;
	if (send)
		stok_answer(tmp, "OK\n");
}

void go_right(t_Server *server, int id, bool send)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->pos.x < server->world->height - 1)
		tmp->pos.x += 1;
	else
		tmp->pos.x = 0;
	if (send)
		stok_answer(tmp, "OK\n");
}

void go_down(t_Server *server, int id, bool send)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->pos.y < server->world->width - 1)
		tmp->pos.y += 1;
	else
		tmp->pos.y = 0;
	if (send)
		stok_answer(tmp, "OK\n");
}

void go_up(t_Server *server, int id, bool send)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->pos.y > 0)
		tmp->pos.y -= 1;
	else
		tmp->pos.y = server->world->width - 1;
	if (send)
		stok_answer(tmp, "OK\n");
}
