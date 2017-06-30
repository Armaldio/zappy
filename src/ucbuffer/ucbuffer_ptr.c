/*
** ucbuffer_ptr.c for  in /home/bonett_w/Documents/epitech/unix_cbuffer/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Fri Jun 30 10:49:57 2017 Walter Bonetti
** Last update Fri Jun 30 10:50:52 2017 Walter Bonetti
*/

#include "unix_cbuffer.h"

inline char	*ucbuffer_head_ptr(t_ucbuffer *ucbuffer)
{
  return (&ucbuffer->buffer[ucbuffer->head]);
}

inline char	*ucbuffer_tail_ptr(t_ucbuffer *ucbuffer)
{
  return (&ucbuffer->buffer[ucbuffer->tail]);
}
