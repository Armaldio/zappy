/*
** poll2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/game/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 16:06:09 2017 Martin Alais
** Last update Sun Jul  2 17:50:01 2017 martin alais
*/

#include <poll.h>
#include "zappy.h"

int		poll_nbr_fd2(t_Server *server)
{
  t_Player	*tmp3;
  int		nbr;

  nbr = 0;
  tmp3 = server->list_player;
  while (tmp3)
    {
      if (tmp3->controlled == true)
	nbr += 1;
      tmp3 = tmp3->next;
    }
  return (nbr);
}

void		complete_struct2(t_Server *server, void *poll_fd, int nbr)
{
  t_Player	*tmp3;
  struct pollfd *data;

  data = poll_fd;
  tmp3 = server->list_player;
  while (tmp3)
    {
      if (tmp3->controlled == true)
	{
	  data[nbr].fd = tmp3->fd;
	  data[nbr].events = ucbuffer_is_empty(tmp3->write_buffer) ?
	    (POLLIN) : (POLLIN | POLLOUT);
	  nbr += 1;
	}
      tmp3 = tmp3->next;
    }
}

bool		send_for_graphic(t_Server *server, int fd, char *data_recv)
{
  t_graphic	*tmp;
  int		a;

  tmp = server->list_graphic;
  while (tmp)
    {
      if (tmp->fd == fd)
	{
	  a = ucbuffer_fromfd(tmp->fd, tmp->read_buffer, 1024);
	  if (a <= 0)
	    {
	      printf("Graphic with id %d disconected\n", tmp->id);
	      delete_graphic(server, tmp->id);
	      return (false);
	    }
	  else
	    {
	      ucbuffer_move(tmp->read_buffer, &tmp->read_buffer->tail, a);
	      complete_read_graphic(tmp, data_recv, server);
	    }
	  return (true);
	}
      tmp = tmp->next;
    }
  return (false);
}

bool		send_for_undefine(t_Server *server, int fd, char *data_recv)
{
  t_undefined	*tmp2;
  int		a;

  tmp2 = server->list_undefined;
  while (tmp2)
    {
      if (tmp2->fd == fd)
	{
	  a = ucbuffer_fromfd(tmp2->fd, tmp2->read_buffer, 1024);
	  if (a <= 0)
	    {
	      printf("Undefine with id %d disconected\n", tmp2->id);
	      delete_undefine(server, tmp2->id);
	      return (false);
	    }
	  ucbuffer_move(tmp2->read_buffer, &tmp2->read_buffer->tail, a);
	  complete_read_undefine(tmp2, data_recv, server);
	  return (true);
	}
      tmp2 = tmp2->next;
    }
  return (false);
}

void	complete_read(t_Player *tmp3, char *data_recv)
{
  int	a;

  a = zappy_getline(tmp3->read_buffer, data_recv);
  strcat(data_recv, "\n");
  printf("%d: %s", tmp3->id, data_recv);
  add_data_in_line(tmp3, data_recv);
  memset(data_recv, '\0', 4095);
  while (a > 0)
    {
      a = zappy_getline(tmp3->read_buffer, data_recv);
      if (a != 0)
	{
	  strcat(data_recv, "\n");
	  printf("%d: %s", tmp3->id, data_recv);
	  add_data_in_line(tmp3, data_recv);
	  memset(data_recv, '\0', 4095);
	}
    }
}
