/*
** ubuffer.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/ucbuffer/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Fri Jun 30 14:20:42 2017 Martin Alais
** Last update Fri Jun 30 14:21:27 2017 Martin Alais
*/

#include "zappy.h"
#include "unix_cbuffer.h"

ssize_t    zappy_getline(t_ucbuffer *ucbuffer, char *buffer)
{
  char    i_buffer[4096];
  char    *cr;
  ssize_t    ret;

  if (ucbuffer_is_empty(ucbuffer))
   return (0);
  ret = ucbuffer_read(ucbuffer, i_buffer, 4096);
  cr = strchr(&i_buffer[0], '\n');
  if (cr == NULL)
    return ((ucbuffer_is_full(ucbuffer)) ? -1 : 0);
  ret = cr - &i_buffer[0];
  ucbuffer_move(ucbuffer, &ucbuffer->head, ret + 1);
  strncpy(buffer, &i_buffer[0], ret);
  buffer[ret] = 0;
  return (ret);
}

ssize_t    zappy_ucbuffer_send(int fd, t_ucbuffer *rb)
{
  const size_t    length = ucbuffer_size_used(rb);
  const ssize_t    ret = ucbuffer_infd(fd, rb, length);

  if (ret <= 0)
    return (ret);
  ucbuffer_move(rb, &rb->head, ret);
  return (ret);
}
