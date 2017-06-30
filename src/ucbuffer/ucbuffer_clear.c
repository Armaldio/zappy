/*
** ucbuffer_clear.c for  in /home/bonett_w/Documents/epitech/unix_cbuffer/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Fri Jun 30 10:45:06 2017 Walter Bonetti
** Last update Fri Jun 30 10:47:25 2017 Walter Bonetti
*/

#include <string.h>
#include "unix_cbuffer.h"

void	ucbuffer_clear(t_ucbuffer *ucbuffer)
{
  ucbuffer->head = 0;
  ucbuffer->tail = 0;
}

void	ucbuffer_bzero(t_ucbuffer *ucbuffer)
{
  bzero(ucbuffer->buffer, ucbuffer->buffer_size);
  ucbuffer_clear(ucbuffer);
}
