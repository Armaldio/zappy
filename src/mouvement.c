#include "mouvement.h"

void go_up(t_Server *server, int id)
{
	t_Player *tmp;

	tmp = server->list_player;
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->pos.x > 0)
	{
		if (case_occupation(server->world, tmp->pos.x - 1, tmp->pos.y) == false)
		{
			set_occupation(server->world, tmp->pos.x - 1, tmp->pos.y, true);
			set_occupation(server->world, tmp->pos.x, tmp->pos.y, false);
			tmp->pos.x -= 1;
		}
	}
	else
	{
		if (case_occupation(server->world, server->world->height - 1, tmp->pos.y) == false)
		{
			set_occupation(server->world, server->world->height - 1, tmp->pos.y, true);
			set_occupation(server->world, tmp->pos.x, tmp->pos.y, false);
			tmp->pos.x = server->world->height - 1;
		}
	}
}

void go_down(t_Server *server, int id)
{
	t_Player *tmp;

	tmp = server->list_player;
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->pos.x < server->world->height - 1)
	{
		if (case_occupation(server->world, tmp->pos.x + 1, tmp->pos.y) == false)
		{
			set_occupation(server->world, tmp->pos.x + 1, tmp->pos.y, true);
			set_occupation(server->world, tmp->pos.x, tmp->pos.y, false);
			tmp->pos.x += 1;
		}
	}
	else
	{
		if (case_occupation(server->world, 0, tmp->pos.y) == false)
		{
			set_occupation(server->world, 0, tmp->pos.y, true);
			set_occupation(server->world, tmp->pos.x, tmp->pos.y, false);
			tmp->pos.x = 0;
		}
	}
}



void go_right(t_Server *server, int id)
{
	t_Player *tmp;

	tmp = server->list_player;
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->pos.y < server->world->width - 1)
	{
		if (case_occupation(server->world, tmp->pos.x, tmp->pos.y + 1) == false)
		{
			set_occupation(server->world, tmp->pos.x, tmp->pos.y + 1, true);
			set_occupation(server->world, tmp->pos.x, tmp->pos.y, false);
			tmp->pos.y += 1;
		}
	}
	else
	{
		if (case_occupation(server->world, tmp->pos.x, 0) == false)
		{
			set_occupation(server->world, tmp->pos.x, 0, true);
			set_occupation(server->world, tmp->pos.x, tmp->pos.y, false);
			tmp->pos.y = 0;
		}
	}
}

void go_left(t_Server *server, int id)
{
	t_Player *tmp;

	tmp = server->list_player;
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->pos.y > 0)
	{
		if (case_occupation(server->world, tmp->pos.x, tmp->pos.y - 1) == false)
		{
			set_occupation(server->world, tmp->pos.x, tmp->pos.y - 1, true);
			set_occupation(server->world, tmp->pos.x, tmp->pos.y, false);
			tmp->pos.y -= 1;
		}
	}
	else
	{
		if (case_occupation(server->world, tmp->pos.x, server->world->width - 1) == false)
		{
			set_occupation(server->world, tmp->pos.x, server->world->width - 1, true);
			set_occupation(server->world, tmp->pos.x, tmp->pos.y, false);
			tmp->pos.y = server->world->width - 1;
		}
	}
}
