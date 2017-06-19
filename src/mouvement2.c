#include "mouvement.h"


void go_up2(t_Server *server, t_Player *tmp)
{
	if (case_occupation(server->world, server->world->height - 1, tmp->pos.y) == false)
	{
		set_occupation(server->world, server->world->height - 1, tmp->pos.y, true);
		set_occupation(server->world, tmp->pos.x, tmp->pos.y, false);
		tmp->pos.x = server->world->height - 1;
		send_message(tmp->fd, "OK\n");
		return;
	}
	else
		send_message(tmp->fd, "KO\n");
}

void go_down2(t_Server *server, t_Player *tmp)
{
	if (case_occupation(server->world, 0, tmp->pos.y) == false)
	{
		set_occupation(server->world, 0, tmp->pos.y, true);
		set_occupation(server->world, tmp->pos.x, tmp->pos.y, false);
		tmp->pos.x = 0;
		send_message(tmp->fd, "OK\n");
		return;
	}
	else
		send_message(tmp->fd, "KO\n");
}

void go_right2(t_Server *server, t_Player *tmp)
{
	if (case_occupation(server->world, tmp->pos.x, 0) == false)
	{
		set_occupation(server->world, tmp->pos.x, 0, true);
		set_occupation(server->world, tmp->pos.x, tmp->pos.y, false);
		tmp->pos.y = 0;
		send_message(tmp->fd, "OK\n");
		return;
	}
	else
		send_message(tmp->fd, "KO\n");
}

void go_left2(t_Server *server, t_Player *tmp)
{
	if (case_occupation(server->world, tmp->pos.x, server->world->width - 1) == false)
	{
		set_occupation(server->world, tmp->pos.x, server->world->width - 1, true);
		set_occupation(server->world, tmp->pos.x, tmp->pos.y, false);
		tmp->pos.y = server->world->width - 1;
		send_message(tmp->fd, "OK\n");
		return;
	}
	else
		send_message(tmp->fd, "KO\n");
}
