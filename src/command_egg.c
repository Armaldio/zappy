/*
** command_egg.c for zappy in /home/hammouche/Documents/PSU_2016/zappy/src/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Thu Jun 22 18:51:56 2017 hamza hammouche
** Last update Thu Jun 22 19:16:46 2017 hamza hammouche
*/

#include "zappy.h"
#include "Incantation.h"

void	send_message_enw(t_Player *p, int idOeuf)
{
  char buffer[512];

  sprintf(buffer, "enw %d %d %d %d\n", idOeuf, p->id, p->pos.x, p->pos.y);
  send_message(p->fd, buffer);
}

void	send_message_ebo(t_Player *p, int idOeuf)
{
  char buffer[512];

  sprintf(buffer, "ebo %d\n", idOeuf);
  send_message(p->fd, buffer);
}
