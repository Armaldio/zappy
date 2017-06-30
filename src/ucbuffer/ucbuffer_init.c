/*
** ucbuffer_init.c for  in /home/bonett_w/Documents/epitech/unix_cbuffer/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Fri Jun 30 10:23:29 2017 Walter Bonetti
** Last update Fri Jun 30 12:17:34 2017 Walter Bonetti
*/

#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include "unix_cbuffer.h"

static unsigned long upper_power_of_two(unsigned long v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

t_ucbuffer	*ucbuffer_new(size_t buffer_size)
{
  t_ucbuffer	*rb;

  buffer_size = (buffer_size < 4096) ? 4096 : buffer_size;
  buffer_size = upper_power_of_two(buffer_size);
  if ((rb = (t_ucbuffer *)malloc(sizeof(t_ucbuffer))) == NULL)
    return (NULL);
  bzero(rb, sizeof(t_ucbuffer));
  rb->buffer_size = buffer_size;
  rb->allocated = 1;
  return (ucbuffer_init(rb));
}

t_ucbuffer	*ucbuffer_init(t_ucbuffer *rb)
{
  char		path[] = "/tmp/cb-XXXXXX";
  const size_t	octets = rb->buffer_size * sizeof(*rb->buffer);
  int		status;
  int		fd;

  fd = mkstemp(path);
  if (fd < 0 || (status = unlink(path)) || (status = ftruncate(fd, octets)))
    return (NULL);
  if ((rb->buffer = (char *)mmap(NULL, octets << 1, PROT_NONE,
		     MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)) == MAP_FAILED ||
      (rb->buffer_a = (char *)mmap(rb->buffer, octets, PROT_READ | PROT_WRITE,
		       MAP_FIXED | MAP_SHARED, fd, 0)) != rb->buffer
    || (rb->buffer_b = (char *)mmap(rb->buffer + octets, octets,
			PROT_READ | PROT_WRITE, MAP_FIXED | MAP_SHARED, fd, 0))
      != rb->buffer + octets)
    return (NULL);
  status = close(fd);
  return ((status == -1) ? NULL : rb);
}

void ucbuffer_delete(t_ucbuffer *rb)
{
  const size_t	octets = rb->buffer_size * sizeof(*rb->buffer);

  if (rb->buffer == NULL)
    return ;
  munmap(rb->buffer_a, octets);
  munmap(rb->buffer_b, octets);
  munmap(rb->buffer, octets << 1);
  rb->buffer_a = 0;
  rb->buffer_b = 0;
  rb->buffer = 0;
  if (rb->allocated == 1)
    free(rb);
}
