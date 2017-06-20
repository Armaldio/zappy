/*
** init_world2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Tue Jun 20 17:33:43 2017 Martin Alais
** Last update Tue Jun 20 17:40:18 2017 Martin Alais
*/

#include "zappy.h"

void init_case2(t_Map *tmp)
{
	tmp->sibur = 0;
    if (rand() % 3 == 0)
      tmp->sibur = 1;
    tmp->thystane = 0;
    if (rand() % 3 == 0)
      tmp->thystane = 1;
    tmp->food = 0;
    if (rand() % 3 == 0)
      tmp->food = 1;
    tmp->is_occuped = false;
}
