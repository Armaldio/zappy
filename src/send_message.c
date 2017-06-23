/*
** send_message.c for zappy in /home/hammouche/Documents/PSU_2016/zappy/src/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Fri Jun 23 11:45:52 2017 hamza hammouche
** Last update Fri Jun 23 11:49:11 2017 hamza hammouche
*/

#include "zappy.h"
#include "Incantation.h"

void	send_message_position(t_Player *head, int x, int y, char *msg)
{
  t_Player *tmp;

  tmp = head;
  while (tmp)
    {
      if (tmp->pos.x == x && tmp->pos.y == y)
				send_message(tmp->fd, msg);
      tmp = tmp->next;
    }
}
