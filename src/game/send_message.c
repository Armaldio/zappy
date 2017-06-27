/*
** send_message.c for zappy in /home/hammouche/Documents/PSU_2016/zappy/src/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Fri Jun 23 11:45:52 2017 hamza hammouche
** Last update Sat Jun 24 19:21:11 2017 hamza hammouche
*/

#include "zappy.h"
#include "Incantation.h"

void	send_message_position(t_graphic *head, char *msg)
{
  t_graphic *tmp;

  tmp = head;
  while (tmp)
    {
      send_message(tmp->fd, msg);
      tmp = tmp->next;
    }
}
