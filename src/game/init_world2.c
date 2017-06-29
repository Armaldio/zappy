/*
** init_world2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Tue Jun 20 17:33:43 2017 Martin Alais
** Last update Thu Jun 29 15:07:35 2017 Martin Alais
*/

#include "zappy.h"

void init_case2(t_Map *tmp)
{
	tmp->sibur = 0;
    if (rand() % 3 == 0)
      tmp->sibur = 1;
    tmp->thystane = 1;
    if (rand() % 10 == 0)
      tmp->thystane = 1;
    tmp->food = 0;
}

void add_rand_food(t_Server *server)
{
	int x;
	int y;

	x = rand() % server->world->width;
	y = rand() % server->world->height;
	server->world->map[x][y] += rand() % 2;
	send_message_bct_pos(server, server->list_graphic, x, y);
}
