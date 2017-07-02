/*
** Eggs.c for  in /home/goinau_q/rendu/c/zappy/src/
**
** Made by Quentin Goinaud
** Login   <quentin.goinaud@epitech.eu>
**
** Started on  Fri Jun 23 10:10:31 2017 Quentin Goinaud
** Last update Sun Jul  2 17:38:28 2017 martin alais
*/

#include "zappy.h"
#include "Player.h"

t_Player	*get_Egg(int id, t_Player *head)
{
  t_Player	*tmp;

  tmp = head;
  while (tmp)
    {
      if (tmp->id == id && tmp->isEgg == true)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}
