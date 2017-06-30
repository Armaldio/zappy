/*
** ucbuffer_size.c for  in /home/bonett_w/Documents/epitech/unix_cbuffer/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Fri Jun 30 10:58:01 2017 Walter Bonetti
** Last update Fri Jun 30 13:38:45 2017 Walter Bonetti
*/

#include "unix_cbuffer.h"

size_t	ucbuffer_size_used(t_ucbuffer *rb)
{
  return ((rb->tail < rb->head)
	  ? (rb->tail + rb->buffer_size) - rb->head : (rb->tail - rb->head));
}

inline size_t	ucbuffer_size(t_ucbuffer *rb)
{
  return (rb->buffer_size);
}

size_t	ucbuffer_freeuse(t_ucbuffer *rb)
{
  return (rb->buffer_size - 1 - (ucbuffer_size_used(rb)));
}
