/*
** set_object.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 12:01:41 2017 Martin Alais
** Last update Thu Jun 22 12:05:57 2017 Martin Alais
*/

#include "Server.h"

void set_linemate(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->inventaire->linemate >= 1)
	{
		server->world->map[tmp->pos.x][tmp->pos.y]->linemate += 1;
		tmp->inventaire->linemate -= 1;
		send_message(tmp->fd, "OK\n");
	}
	else
		send_message(tmp->fd, "KO\n");
}

void set_deraumere(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->inventaire->deraumere += 1 >= 1)
	{
		server->world->map[tmp->pos.x][tmp->pos.y]->deraumere += 1;
		tmp->inventaire->deraumere -= 1;
		send_message(tmp->fd, "OK\n");
	}
	else
		send_message(tmp->fd, "KO\n");
}

void set_sibur(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->inventaire->sibur >= 1)
	{
		server->world->map[tmp->pos.x][tmp->pos.y]->sibur += 1;
		tmp->inventaire->sibur -= 1;
		send_message(tmp->fd, "OK\n");
	}
	else
		send_message(tmp->fd, "KO\n");
}

void set_mendiane(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->inventaire->mendiane >= 1)
	{
		server->world->map[tmp->pos.x][tmp->pos.y]->mendiane += 1;
		tmp->inventaire->mendiane -= 1;
		send_message(tmp->fd, "OK\n");
	}
	else
		send_message(tmp->fd, "KO\n");
}

void set_phiras(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->inventaire->phiras >= 1)
	{
		server->world->map[tmp->pos.x][tmp->pos.y]->phiras += 1;
		tmp->inventaire->phiras -= 1;
		send_message(tmp->fd, "OK\n");
	}
	else
		send_message(tmp->fd, "KO\n");
}
