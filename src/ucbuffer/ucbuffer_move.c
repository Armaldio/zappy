/*
** ucbuffer_move.c for  in /home/bonett_w/Documents/epitech/unix_cbuffer/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Fri Jun 30 11:33:07 2017 Walter Bonetti
** Last update Fri Jun 30 13:28:04 2017 Walter Bonetti
*/

#include "unix_cbuffer.h"

void	ucbuffer_move(t_ucbuffer *rb, size_t *hdotl, size_t size)
{
  *hdotl = (*hdotl + size) % rb->buffer_size;
}
