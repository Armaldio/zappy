/*
** ucbuffer_printer.c for  in /home/bonett_w/Documents/epitech/unix_cbuffer/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Fri Jun 30 10:51:25 2017 Walter Bonetti
** Last update Fri Jun 30 11:40:45 2017 Walter Bonetti
*/

#include "unix_cbuffer.h"

void	ucbuffer_print_used(t_ucbuffer *ucbuffer, t_print_char printer)
{
  const size_t	c_length = ucbuffer_size_used(ucbuffer);
  size_t	i;

  i = ucbuffer->head;
  while (i < c_length)
    {
      printer(&ucbuffer->buffer[i]);
      i++;
    }
}

void	ucbuffer_print_all(t_ucbuffer *ucbuffer, t_print_char printer)
{
  const size_t	c_length = ucbuffer_size(ucbuffer);
  size_t	i;

  i = 0;
  while (i < c_length)
    {
      printer(&ucbuffer->buffer[i]);
      i++;
    }
}
