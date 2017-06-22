/*
** take_object.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Tue Jun 20 09:45:19 2017 loic1.doyen@epitech.eu
** Last update Thu Jun 22 17:34:11 2017 hamza hammouche
*/

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
		server->isGraphic == true ? send_message_take(tmp->fd, tmp->id, 1) :
	  send_message(tmp->fd, "ok\n");
	}
	else
		send_message(tmp->fd, "ko\n");
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
		server->isGraphic == true ? send_message_take(tmp->fd, tmp->id, 2) :
    send_message(tmp->fd, "ok\n");
	}
	else
		send_message(tmp->fd, "ko\n");
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
		server->isGraphic == true ? send_message_take(tmp->fd, tmp->id, 3) :
    send_message(tmp->fd, "ok\n");
	}
	else
		send_message(tmp->fd, "ko\n");
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
		server->isGraphic == true ? send_message_take(tmp->fd, tmp->id, 4) :
	  send_message(tmp->fd, "ok\n");
	}
	else
		send_message(tmp->fd, "ko\n");
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
		server->isGraphic == true ? send_message_take(tmp->fd, tmp->id, 5) :
    send_message(tmp->fd, "ok\n");
	}
	else
		send_message(tmp->fd, "ko\n");
}
