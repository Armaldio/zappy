/*
** World.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Tue Jun 20 09:45:26 2017 loic1.doyen@epitech.eu
** Last update Wed Jun 28 15:37:14 2017 Martin Alais
*/

#include "zappy.h"

t_Map *init_case()
{
  t_Map *tmp;

  tmp = malloc(sizeof(t_Map));
  tmp->deraumere = 1;
  // if (rand() % 3 == 0)
  //   tmp->deraumere = 1;
  tmp->linemate = 1;
  // if (rand() % 3 == 0)
  //   tmp->linemate = 1;
  tmp->mendiane = 0;
  // if (rand() % 3 == 0)
  //   tmp->mendiane = 1;
  tmp->phiras = 0;
  // if (rand() % 3 == 0)
  //   tmp->phiras = 1;
	init_case2(tmp);
  return (tmp);
}

void basic_init_world(t_World * world)
{
  world->height = -1;
  world->width = -1;
  world->nbr_player = 0;
}

void print_world(t_World *world)
{
  int a;
  int b;

  a = 0;
  while (world->map[a] != NULL)
    {
      b = 0;
      while (world->map[a][b] != NULL)
	{
	  printf("Map position: %d - %d\n", a, b);
	  printf("deraumere: %d\n", world->map[a][b]->deraumere);
	  printf("linemate: %d\n", world->map[a][b]->linemate);
	  printf("mendiane: %d\n", world->map[a][b]->mendiane);
	  printf("phiras: %d\n", world->map[a][b]->phiras);
	  printf("sibur: %d\n", world->map[a][b]->sibur);
	  printf("thystane: %d\n", world->map[a][b]->thystane);
	  b += 1;
	}
      a += 1;
    }
}

void init_world(t_World * world)
{
  int a;
  int b;

  b = 0;
  if (world->height == -1)
    world->height = 10;
  if (world->width == -1)
    world->width = 10;
  printf("World initialized with height %d and width %d\n", world->height,
	 world->width);
  a = 0;
  world->map = malloc(sizeof(t_Map **) * (world->height * world->width));
  while (a < world->height)
    {
      world->map[a] = malloc(sizeof(t_Map **) * world->height);
      b = 0;
      while (b < world->width)
	{
	  world->map[a][b] = init_case();
	  b += 1;
	}
      a += 1;
    }
  world->map[a] = NULL;
}
