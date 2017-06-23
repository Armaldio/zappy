/*
** server2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:21:28 2017 Martin Alais
** Last update Fri Jun 23 14:16:42 2017 Martin Alais
*/

#include "Server.h"
#include "Player.h"
#include "Socket.h"
#include "zappy.h"

void basic_init_server(t_Server *server)
{
	server->list_player = my_malloc(sizeof(t_Player));
	server->socket = my_malloc(sizeof(t_Connection));
	server->world = my_malloc(sizeof(t_World));
  server->nbClientMax = 6;
  server->isGraphic = false;
	basic_init_socket(server->socket);
	basic_init_world(server->world);
	server->f = 100;
}

void init_inventaire(t_Player *player, t_Server *server)
{
	player->inventaire = my_malloc(sizeof(t_Inventaire));
	player->inventaire->deraumere = 0;
	player->inventaire->linemate = 0;
	player->inventaire->mendiane = 0;
	player->inventaire->phiras = 0;
	player->inventaire->sibur = 0;
	player->inventaire->thystane = 0;
	player->inventaire->food = my_safe_div((1260 / server->f),
	(126 / server->f));
}

void init_server(t_Server *server)
{
	init_socket(server->socket);

	server->list_player = my_malloc(sizeof(t_Player));
	server->list_player = NULL;
	init_world(server->world);
	server->time = 0;
	server->fake_time = -1;
}

t_Position get_spaw_pos(t_Server *server)
{
	t_Position res;

	res.x = rand() % (server->world->height - 1);
	res.y = rand() % (server->world->width - 1);
	return (res);
}
