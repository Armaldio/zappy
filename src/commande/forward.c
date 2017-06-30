/*
** forward.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:00:57 2017 Martin Alais
** Last update Fri Jun 30 10:59:53 2017 hamza hammouche
*/

#include "zappy.h"
#include "Event.h"

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
		stok_answer(tmp, "ok\n");
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
		stok_answer(tmp, "ok\n");
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
		stok_answer(tmp, "ok\n");
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
		stok_answer(tmp, "ok\n");
}

void commande_forward(int id, t_Server *server, char *data)
{
	t_Player *tmp;

	(void) data;
  tmp = get_Player(id, server->list_player);
	start_action(server, tmp, 7);
	if (tmp->gaze == UP)
		go_up(server, id, true);
	else if (tmp->gaze == DOWN)
		go_down(server, id, true);
	else if (tmp->gaze == RIGHT)
		go_right(server, id, true);
	else
		go_left(server, id, true);
	event_ppo(server, tmp);
}
