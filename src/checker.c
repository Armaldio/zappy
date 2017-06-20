/*
** checker.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Tue Jun 20 09:56:28 2017 loic1.doyen@epitech.eu
** Last update Tue Jun 20 09:56:37 2017 loic1.doyen@epitech.eu
*/

#include "zappy.h"

bool case_occupation(t_World *world, int x, int y)
{
  return (world->map[x][y]->is_occuped);
}
