/*
** eggs.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/event/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 12:23:18 2017 Martin Alais
** Last update Mon Jun 26 12:23:38 2017 Martin Alais
*/

#include "zappy.h"

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
