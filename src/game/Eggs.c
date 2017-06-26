/*
** Eggs.c for  in /home/goinau_q/rendu/c/zappy/src/
**
** Made by Quentin Goinaud
** Login   <quentin.goinaud@epitech.eu>
**
** Started on  Fri Jun 23 10:10:31 2017 Quentin Goinaud
** Last update Sat Jun 24 12:15:21 2017 Martin Alais
*/

#include "zappy.h"
#include "Player.h"

t_Player	*get_Egg(int id, t_Player *head)
{
  t_Player *tmp;

  tmp = head;
  while (tmp)
    {
      if (tmp->id == id && tmp->isEgg == true)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

int	get_New_EggID(t_Player *head)
{
  t_Player *tmp;
  int	last;

  tmp = head;
  last = 0;
  while (tmp)
    {
      if (tmp->isEgg == true)
	last = tmp->id;
      tmp = tmp->next;
    }
  return (last);
}
