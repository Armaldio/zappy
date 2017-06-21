/*
** server2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:21:28 2017 Martin Alais
** Last update Tue Jun 20 17:17:28 2017 Martin Alais
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
	basic_init_socket(server->socket);
	basic_init_world(server->world);
	server->f = 100;
}

void init_inventaire(t_Player *player)
{
	player->inventaire = my_malloc(sizeof(t_Inventaire));
	player->inventaire->deraumere = 0;
	player->inventaire->linemate = 0;
	player->inventaire->mendiane = 0;
	player->inventaire->phiras = 0;
	player->inventaire->sibur = 0;
	player->inventaire->thystane = 0;
}

void init_server(t_Server *server)
{
	init_socket(server->socket);

	server->list_player = malloc(sizeof(t_Player));
	server->list_player = NULL;
	init_world(server->world);
	server->time = 0;
	server->fake_time = -1;
}

t_Position get_spaw_pos(t_Server *server)
{
	t_Position res;

	res.x = 0;
	while (res.x < server->world->height - 1)
	{
		res.y = 0;
		while (res.y < server->world->width - 1)
		{
			if (case_occupation(server->world, res.x, res.y) == false)
				return (res);
			res.y += 1;
		}
		res.x += 1;
	}
	printf("[Error] no more space for spawn\n");
	res.x = -1;
	res.y = -1;
	return (res);
}
