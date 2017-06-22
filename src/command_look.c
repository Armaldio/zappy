/*
** command_look.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Tue Jun 20 11:55:27 2017 loic1.doyen@epitech.eu
** Last update Thu Jun 22 11:12:48 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

void	t_backward(t_Player *tmp, int i, int y, t_Server *server)
{
  int	x;
  int	j;

  x = ((tmp->pos.x - i + y) + server->world->height) % server->world->height;
  j = ((tmp->pos.y - y) + server->world->width) % server->world->width;
  if ((x != 0 || y != 0))
    send_message(tmp->fd, " player");
  if (server->world->map[x][j]->food >= 1)
    send_message(tmp->fd, " food");
  if (server->world->map[x][j]->deraumere >= 1)
    send_message(tmp->fd, " deraumere");
  if (server->world->map[x][j]->linemate >= 1)
    send_message(tmp->fd, " linemate");
  if (server->world->map[x][j]->mendiane >= 1)
    send_message(tmp->fd, " mendiane");
  if (server->world->map[x][j]->phiras >= 1)
    send_message(tmp->fd, " phiras");
  if (server->world->map[x][j]->sibur >= 1)
    send_message(tmp->fd, " sibur");
  if (server->world->map[x][j]->thystane >= 1)
    send_message(tmp->fd, " thystane");
  if (i != tmp->level * 2)
    send_message(tmp->fd, ",");
}

void	t_forward(t_Player *tmp, int i, int y, t_Server *server)
{
  int	x;
  int	j;

  if (tmp->gaze == DOWN)
    {
      t_backward(tmp, i, y, server);
      return ;
    }
  x = ((tmp->pos.x + i - y) + server->world->height) % server->world->height;
  j = ((tmp->pos.y + y) + server->world->width) % server->world->width;
  if ((x != 0 || y != 0))
    send_message(tmp->fd, " player");
  if (server->world->map[x][j]->food >= 1)
    send_message(tmp->fd, " food");
  if (server->world->map[x][j]->deraumere >= 1)
    send_message(tmp->fd, " deraumere");
  if (server->world->map[x][j]->linemate >= 1)
    send_message(tmp->fd, " linemate");
  if (server->world->map[x][j]->mendiane >= 1)
    send_message(tmp->fd, " mendiane");
  if (server->world->map[x][j]->phiras >= 1)
    send_message(tmp->fd, " phiras");
  if (server->world->map[x][j]->sibur >= 1)
    send_message(tmp->fd, " sibur");
  if (server->world->map[x][j]->thystane >= 1)
    send_message(tmp->fd, " thystane");
  if (i != tmp->level * 2)
    send_message(tmp->fd, ",");
}

void	t_right(t_Player *tmp, int i, int y, t_Server *server)
{
  int	x;
  int	j;

  x = ((tmp->pos.x + y) + server->world->height) % server->world->height;
  j = ((tmp->pos.y - i + y) + server->world->width) % server->world->width;
  if ((x != 0 || y != 0))
    send_message(tmp->fd, " player");
  if (server->world->map[x][j]->food >= 1)
    send_message(tmp->fd, " food");
  if (server->world->map[x][j]->deraumere >= 1)
    send_message(tmp->fd, " deraumere");
  if (server->world->map[x][j]->linemate >= 1)
    send_message(tmp->fd, " linemate");
  if (server->world->map[x][j]->mendiane >= 1)
    send_message(tmp->fd, " mendiane");
  if (server->world->map[x][j]->phiras >= 1)
    send_message(tmp->fd, " phiras");
  if (server->world->map[x][j]->sibur >= 1)
    send_message(tmp->fd, " sibur");
  if (server->world->map[x][j]->thystane >= 1)
    send_message(tmp->fd, " thystane");
  if (i != tmp->level * 2)
    send_message(tmp->fd, ",");
}

void	t_left(t_Player *tmp, int i, int y, t_Server *server)
{
  int	x;
  int	j;

  if (tmp->gaze == RIGHT)
    {
      t_right(tmp, i, y, server);
      return ;
    }
  x = ((tmp->pos.x + i - y) + server->world->height) % server->world->height;
  j = ((tmp->pos.y - y) + server->world->width) % server->world->width;
  if ((x != 0 || y != 0))
    send_message(tmp->fd, " player");
  if (server->world->map[x][j]->food >= 1)
    send_message(tmp->fd, " food");
  if (server->world->map[x][j]->deraumere >= 1)
    send_message(tmp->fd, " deraumere");
  if (server->world->map[x][j]->linemate >= 1)
    send_message(tmp->fd, " linemate");
  if (server->world->map[x][j]->mendiane >= 1)
    send_message(tmp->fd, " mendiane");
  if (server->world->map[x][j]->phiras >= 1)
    send_message(tmp->fd, " phiras");
  if (server->world->map[x][j]->sibur >= 1)
    send_message(tmp->fd, " sibur");
  if (server->world->map[x][j]->thystane >= 1)
    send_message(tmp->fd, " thystane");
  if (i != tmp->level * 2)
    send_message(tmp->fd, ",");
}

int		command_look(int id, t_Server *server, char *data)
{
  t_Player	*tmp;
  int		i;
  int		y;

  tmp = server->list_player;
  while (tmp->next && tmp->id != id)
    tmp = tmp->next;
  start_look(server, tmp, data);
  send_message(tmp->fd, "[player");
  y = 0;
  while (y <= tmp->level)
    {
      i = 0;
      while (i < y * 2 + 1)
	{
	  if (tmp->gaze == UP || tmp->gaze == DOWN)
	    t_forward(tmp, i, y, server);
	  else
	    t_left(tmp, i, y, server);
	  i++;
	}
      y++;
    }
  send_message(tmp->fd, "]\n");
  return (0);
}
