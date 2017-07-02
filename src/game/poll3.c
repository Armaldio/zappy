/*
** poll3.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/game/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 29 14:33:37 2017 Martin Alais
** Last update Sun Jul  2 21:17:26 2017 hamza hammouche
*/

#include "zappy.h"
#include <poll.h>

int		get_poll_timeout(t_Server *server)
{
  t_Player	*tmp;
  double	min;
  double	tmp_min;
  int		res;

  tmp = server->list_player;
  res = 50;
  if (tmp == NULL)
    return (res);
  min = -1;
  while (tmp)
    {
      if (tmp->isEgg == false)
	{
	  tmp_min = tmp->action->end_time - tmp->action->start_time;
	  if (tmp_min < min)
	    min = tmp_min;
	}
      tmp = tmp->next;
    }
  if (min == -1)
    res = 50;
  else
    res = (int)min * 1000;
  return (res);
}

int		poll_nbr_fd(t_Server *server)
{
  int		nbr;
  t_graphic	*tmp;
  t_undefined	*tmp2;

  nbr = 0;
  tmp = server->list_graphic;
  tmp2 = server->list_undefined;
  while (tmp)
    {
      nbr += 1;
      tmp = tmp->next;
    }
  while (tmp2)
    {
      nbr += 1;
      tmp2 = tmp2->next;
    }
  nbr += poll_nbr_fd2(server);
  return (nbr);
}

void		complete_struct(t_Server *server, struct pollfd *poll_fd)
{
  t_graphic	*tmp;
  t_undefined	*tmp2;
  int		nbr;

  nbr = 0;
  tmp = server->list_graphic;
  tmp2 = server->list_undefined;
  while (tmp)
    {
      poll_fd[nbr].fd = tmp->fd;
      poll_fd[nbr].events = ucbuffer_is_empty(tmp->write_buffer) ?
	(POLLIN) : (POLLIN | POLLOUT);
      nbr += 1;
      tmp = tmp->next;
    }
  while (tmp2)
    {
      poll_fd[nbr].fd = tmp2->fd;
      poll_fd[nbr].events = ucbuffer_is_empty(tmp2->write_buffer) ?
	(POLLIN) : (POLLIN | POLLOUT);
      nbr += 1;
      tmp2 = tmp2->next;
    }
  complete_struct2(server, poll_fd, nbr);
}

void	player_disconnected(t_Player *player, t_Server *server)
{
  player->is_connected = false;
  printf("Player with id %d disconected\n", player->id);
  send_message_death(server->list_graphic, player->id);
  my_delete_player(server, player->id);
}

int	get_nbr_del(char *str, char del)
{
  int	a;
  int	nbr;

  nbr = 0;
  a = 0;
  while (str[a])
    {
      if (str[a] == del)
	nbr += 1;
      a += 1;
    }
  return (nbr);
}
