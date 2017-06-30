/*
** ucbuffer_bool.c for  in /home/bonett_w/Documents/epitech/unix_cbuffer/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Fri Jun 30 10:48:08 2017 Walter Bonetti
** Last update Fri Jun 30 10:49:28 2017 Walter Bonetti
*/

#include "unix_cbuffer.h"

inline int	ucbuffer_is_full(t_ucbuffer *ucbuffer)
{
  return (ucbuffer->head == ucbuffer->tail + 1);
}

inline int	ucbuffer_is_empty(t_ucbuffer *ucbuffer)
{
  return (ucbuffer->head == ucbuffer->tail);
}
