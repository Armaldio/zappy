/*
** command_egg.c for zappy in /home/hammouche/Documents/PSU_2016/zappy/src/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Thu Jun 22 18:51:56 2017 hamza hammouche
** Last update Sat Jun 24 19:13:27 2017 hamza hammouche
*/

#include "zappy.h"
#include "Incantation.h"

void	send_message_enw(t_graphic *head, t_Player *p, int idOeuf)
{
  char buffer[512];
  t_graphic *tmp;

  sprintf(buffer, "enw %d %d %d %d\n", idOeuf, p->id, p->pos.x, p->pos.y);
  tmp = head;
  while (tmp)
    {
      send_message(tmp->fd, buffer);
      tmp = tmp->next;
    }
  stok_answer(p, buffer);
}

void	send_message_ebo(t_Player *p, int idOeuf)
{
  char buffer[512];

  sprintf(buffer, "ebo %d\n", idOeuf);
  stok_answer(p, buffer);
}
