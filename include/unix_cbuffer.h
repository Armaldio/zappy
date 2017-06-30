/*
** unix_cbuffer.h for  in /home/bonett_w/Documents/epitech/unix_cbuffer/include/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Fri Jun 30 09:59:35 2017 Walter Bonetti
** Last update Fri Jun 30 14:32:29 2017 Martin Alais
*/

#ifndef UNIX_CBUFFER
# define UNIX_CBUFFER

# include <unistd.h>

typedef struct	s_ucbuffer {
  char		*buffer;
  char		*buffer_a;
  char		*buffer_b;
  size_t	head;
  size_t	tail;
  size_t	buffer_size;
  char		allocated;
}		t_ucbuffer;

typedef void(*t_print_char)(char *);

t_ucbuffer	*ucbuffer_new(size_t buffer_size);

t_ucbuffer	*ucbuffer_init(t_ucbuffer *ucbuffer);

void ucbuffer_delete(t_ucbuffer *ucbuffer);

int	ucbuffer_is_full(t_ucbuffer *ucbuffer);

int	ucbuffer_is_empty(t_ucbuffer *ucbuffer);

void	ucbuffer_clear(t_ucbuffer *ucbuffer);

void	ucbuffer_bzero(t_ucbuffer *ucbuffer);

char	*ucbuffer_head_ptr(t_ucbuffer *ucbuffer);

char	*ucbuffer_tail_ptr(t_ucbuffer *ucbuffer);

void	ucbuffer_print_used(t_ucbuffer *ucbuffer, t_print_char printer);

void	ucbuffer_print_all(t_ucbuffer *ucbuffer, t_print_char printer);

void	ucbuffer_move(t_ucbuffer *rb, size_t *hdotl, size_t size);

size_t	ucbuffer_size_used(t_ucbuffer *ucbuffer);

size_t	ucbuffer_size(t_ucbuffer *ucbuffer);

size_t	ucbuffer_freeuse(t_ucbuffer *ucbuffer);

ssize_t	ucbuffer_write(t_ucbuffer *rb, const char *data, size_t size);
ssize_t	ucbuffer_read(t_ucbuffer *rb, char *data, size_t size);
ssize_t	ucbuffer_infd(int fd, t_ucbuffer *rb, size_t size);
ssize_t ucbuffer_fromfd(int fd, t_ucbuffer *rb, size_t size);

ssize_t    zappy_getline(t_ucbuffer *ucbuffer, char *buffer);

ssize_t    zappy_ucbuffer_send(int fd, t_ucbuffer *rb);

#endif /* end of include guard: UNIX_CBUFFER */
