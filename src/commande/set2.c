/*
** set2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:36:03 2017 Martin Alais
** Last update Mon Jun 26 13:36:34 2017 Martin Alais
*/

#include "zappy.h"
#include "Event.h"

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
		event_drop(server, tmp, 1);
		stok_answer(tmp, "ok\n");
	}
	else
		stok_answer(tmp, "ko\n");
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
		event_drop(server, tmp, 2);
		stok_answer(tmp, "ok\n");
	}
	else
		stok_answer(tmp, "ko\n");
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
		event_drop(server, tmp, 3);
		stok_answer(tmp, "ok\n");
	}
	else
		stok_answer(tmp, "ko\n");
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
		event_drop(server, tmp, 4);
		stok_answer(tmp, "ok\n");
	}
	else
		stok_answer(tmp, "ko\n");
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
		event_drop(server, tmp, 5);
		stok_answer(tmp, "ok\n");
	}
	else
		stok_answer(tmp, "ko\n");
}
