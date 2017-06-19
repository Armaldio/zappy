#include "mouvement.h"

void go_up(t_Server *server, int id)
{
	t_Player *tmp;

	tmp = server->list_player;
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->pos.x > 0)
		tmp->pos.x -= 1;
	else
		tmp->pos.x = server->world->height;
}

void go_down(t_Server *server, int id)
{
	t_Player *tmp;

	tmp = server->list_player;
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->pos.x < server->world->height)
		tmp->pos.x += 1;
	else
		tmp->pos.x = 0;
}

void go_right(t_Server *server, int id)
{
	t_Player *tmp;

	tmp = server->list_player;
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->pos.y < server->world->width)
		tmp->pos.y += 1;
	else
		tmp->pos.y = 0;
}

void go_left(t_Server *server, int id)
{
	t_Player *tmp;

	tmp = server->list_player;
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->pos.y > 0)
		tmp->pos.y -= 1;
	else
		tmp->pos.y = server->world->width;
}
