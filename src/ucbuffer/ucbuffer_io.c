/*
** ucbuffer_io.c for  in /home/bonett_w/Documents/epitech/unix_cbuffer/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Fri Jun 30 11:02:51 2017 Walter Bonetti
** Last update Fri Jun 30 13:56:21 2017 Walter Bonetti
*/

#include <string.h>
#include <unistd.h>
#include "unix_cbuffer.h"

ssize_t	ucbuffer_write(t_ucbuffer *rb, const char *data, size_t size)
{
  const size_t	fuse = ucbuffer_freeuse(rb);

  if (size > fuse)
    return (-1);
  memcpy(&rb->buffer[rb->tail], data, size);
  return (size);
}

ssize_t	ucbuffer_read(t_ucbuffer *rb, char *data, size_t size)
{
  const size_t	distance = ucbuffer_size_used(rb);
  const size_t	octets = (size < distance) ? size : distance;

  memcpy(data, &rb->buffer[rb->head], octets);
  return (octets);
}

ssize_t	ucbuffer_infd(int fd, t_ucbuffer *rb, size_t size)
{
  const size_t	distance = ucbuffer_size_used(rb);
  ssize_t	ret;

  if (size > distance)
    return (-1);
  ret = write(fd, &rb->buffer[rb->head], size);
  return (ret);
}

ssize_t ucbuffer_fromfd(int fd, t_ucbuffer *rb, size_t size)
{
  const size_t	fuse = ucbuffer_freeuse(rb);
  ssize_t	ret;

  if (size > fuse)
    return (-1);

  ret = read(fd, &rb->buffer[rb->tail], size);
  return (ret);
}
