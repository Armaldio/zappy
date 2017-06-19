#include "Server.h"

void take_linemate(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (server->world->map[tmp->pos.x][tmp->pos.y]->linemate >= 1)
	{
		server->world->map[tmp->pos.x][tmp->pos.y]->linemate -= 1;
		tmp->inventaire->linemate += 1;
		send_message(tmp->fd, "OK\n");
	}
	else
		send_message(tmp->fd, "KO\n");
}

void take_deraumere(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (server->world->map[tmp->pos.x][tmp->pos.y]->deraumere >= 1)
	{
		server->world->map[tmp->pos.x][tmp->pos.y]->deraumere -= 1;
		tmp->inventaire->deraumere += 1;
		send_message(tmp->fd, "OK\n");
	}
	else
		send_message(tmp->fd, "KO\n");
}

void take_sibur(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (server->world->map[tmp->pos.x][tmp->pos.y]->sibur >= 1)
	{
		server->world->map[tmp->pos.x][tmp->pos.y]->sibur -= 1;
		tmp->inventaire->sibur += 1;
		send_message(tmp->fd, "OK\n");
	}
	else
		send_message(tmp->fd, "KO\n");
}

void take_mendiane(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (server->world->map[tmp->pos.x][tmp->pos.y]->mendiane >= 1)
	{
		server->world->map[tmp->pos.x][tmp->pos.y]->mendiane -= 1;
		tmp->inventaire->mendiane += 1;
		send_message(tmp->fd, "OK\n");
	}
	else
		send_message(tmp->fd, "KO\n");
}

void take_phiras(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (server->world->map[tmp->pos.x][tmp->pos.y]->phiras >= 1)
	{
		server->world->map[tmp->pos.x][tmp->pos.y]->phiras -= 1;
		tmp->inventaire->phiras += 1;
		send_message(tmp->fd, "OK\n");
	}
	else
		send_message(tmp->fd, "KO\n");
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
		send_message(tmp->fd, "OK\n");
	}
	else
		send_message(tmp->fd, "KO\n");
}
