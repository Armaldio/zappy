/*
** Player.c for zappy in /home/hammouche/Documents/PSU_2016/zappy/src/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Tue Jun 20 09:35:13 2017 hamza hammouche
** Last update Sun Jul  2 18:14:22 2017 martin alais
*/

#include "Player.h"

t_Player	*get_First_Player_Available(t_Player *head)
{
  t_Player	*tmp;

  tmp = head;
  while (tmp)
    {
      if (tmp->is_connected == false &&
	  tmp->controlled == false &&
	  tmp->isEgg == false)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

t_Player	*get_Player(int id, t_Player *head)
{
  t_Player	*tmp;

  tmp = head;
  while (tmp)
    {
      if (tmp->id == id && tmp->isEgg == false)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

int		get_New_PlayerID(t_Player *head)
{
  t_Player	*tmp;
  int		last;

  tmp = head;
  last = 0;
  while (tmp)
    {
      if (tmp->isEgg == false)
	last = tmp->id;
      tmp = tmp->next;
    }
  return (last);
}
