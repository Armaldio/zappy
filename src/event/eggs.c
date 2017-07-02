/*
** eggs.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/event/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 12:23:18 2017 Martin Alais
** Last update Sun Jul  2 17:30:28 2017 martin alais
*/

#include "zappy.h"

void	send_message_ebo(t_Player *p, int idOeuf)
{
  char	buffer[512];

  sprintf(buffer, "ebo %d\n", idOeuf);
  stok_answer(p, buffer);
}
