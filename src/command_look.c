/*
** command_look.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Tue Jun 20 11:55:27 2017 loic1.doyen@epitech.eu
** Last update Tue Jun 20 13:00:18 2017 Quentin Goinaud
*/

#include "zappy.h"
#include "Incantation.h"

void t_backward(t_Player *tmp, int i, int y, t_Server *server)
{
  if (tmp->pos.x - i + y < 0 || tmp->pos.y - y < 0 ||
      tmp->pos.x - i + y > server->world->width ||
      tmp->pos.y - y > server->world->height)
    return ;
  if (server->world->map[tmp->pos.x - i + y][tmp->pos.y - y]->deraumere >= 1)
    send_message(tmp->fd, " deraumere");
  if (server->world->map[tmp->pos.x - i + y][tmp->pos.y - y]->linemate >= 1)
    send_message(tmp->fd, " linemate");
  if (server->world->map[tmp->pos.x - i + y][tmp->pos.y - y]->mendiane >= 1)
    send_message(tmp->fd, " mendiane");
  if (server->world->map[tmp->pos.x - i + y][tmp->pos.y - y]->phiras >= 1)
    send_message(tmp->fd, " phiras");
  if (server->world->map[tmp->pos.x - i + y][tmp->pos.y - y]->sibur >= 1)
    send_message(tmp->fd, " sibur");
  if (server->world->map[tmp->pos.x - i + y][tmp->pos.y - y]->thystane >= 1)
    send_message(tmp->fd, " thystane");
  if (i != tmp->level * 2)
    send_message(tmp->fd, ",");
}

void t_forward(t_Player *tmp, int i, int y, t_Server *server)
{
  if (tmp->gaze == DOWN)
    {
      t_backward(tmp, i, y, server);
      return;
    }
  if (tmp->pos.x + i - y < 0 || tmp->pos.y + y < 0 ||
      tmp->pos.x + i - y > server->world->width ||
      tmp->pos.y + y > server->world->height)
    return;
  if (server->world->map[tmp->pos.x + i - y][tmp->pos.y + y]->deraumere >= 1)
    send_message(tmp->fd, " deraumere");
  if (server->world->map[tmp->pos.x + i - y][tmp->pos.y + y]->linemate >= 1)
    send_message(tmp->fd, " linemate");
  if (server->world->map[tmp->pos.x + i - y][tmp->pos.y + y]->mendiane >= 1)
    send_message(tmp->fd, " mendiane");
  if (server->world->map[tmp->pos.x + i - y][tmp->pos.y + y]->phiras >= 1)
    send_message(tmp->fd, " phiras");
  if (server->world->map[tmp->pos.x + i - y][tmp->pos.y + y]->sibur >= 1)
    send_message(tmp->fd, " sibur");
  if (server->world->map[tmp->pos.x + i - y][tmp->pos.y + y]->thystane >= 1)
    send_message(tmp->fd, " thystane");
  if (i != tmp->level * 2)
    send_message(tmp->fd, ",");
}

void t_right(t_Player *tmp, int i, int y, t_Server *server)
{
  if (tmp->pos.x + y < 0 || tmp->pos.y - i + y < 0 ||
      tmp->pos.x + y > server->world->width ||
      tmp->pos.y - i + y > server->world->height)
    return;
  if (server->world->map[tmp->pos.x + y][tmp->pos.y - i + y]->deraumere >= 1)
    send_message(tmp->fd, " deraumere");
  if (server->world->map[tmp->pos.x + y][tmp->pos.y - i + y]->linemate >= 1)
    send_message(tmp->fd, " linemate");
  if (server->world->map[tmp->pos.x + y][tmp->pos.y - i + y]->mendiane >= 1)
    send_message(tmp->fd, " mendiane");
  if (server->world->map[tmp->pos.x + y][tmp->pos.y - i + y]->phiras >= 1)
    send_message(tmp->fd, " phiras");
  if (server->world->map[tmp->pos.x + y][tmp->pos.y - i + y]->sibur >= 1)
    send_message(tmp->fd, " sibur");
  if (server->world->map[tmp->pos.x + y][tmp->pos.y - i + y]->thystane >= 1)
    send_message(tmp->fd, " thystane");
  if (i != tmp->level * 2)
    send_message(tmp->fd, ",");
}

void t_left(t_Player *tmp, int i, int y, t_Server *server)
{
  if (tmp->gaze == RIGHT)
    {
      t_right(tmp, i, y, server);
      return;
    }
  if (tmp->pos.y + i - y < 0 || tmp->pos.x - y < 0 ||
      tmp->pos.y + i - y > server->world->width ||
      tmp->pos.x - y > server->world->height)
    return;
  if (server->world->map[tmp->pos.x - y][tmp->pos.y + i - y]->deraumere >= 1)
    send_message(tmp->fd, " deraumere");
  if (server->world->map[tmp->pos.x - y][tmp->pos.y + i - y]->linemate >= 1)
    send_message(tmp->fd, " linemate");
  if (server->world->map[tmp->pos.x - y][tmp->pos.y + i - y]->mendiane >= 1)
    send_message(tmp->fd, " mendiane");
  if (server->world->map[tmp->pos.x - y][tmp->pos.y + i - y]->phiras >= 1)
    send_message(tmp->fd, " phiras");
  if (server->world->map[tmp->pos.x - y][tmp->pos.y + i - y]->sibur >= 1)
    send_message(tmp->fd, " sibur");
  if (server->world->map[tmp->pos.x - y][tmp->pos.y + i - y]->thystane >= 1)
    send_message(tmp->fd, " thystane");
  if (i != tmp->level * 2)
    send_message(tmp->fd, ",");
}

int command_look(int id, t_Server *server, char *data)
{
  t_Player	*tmp;
  int		i;
  int		y;

  (void) data;
  tmp = server->list_player;
  while (tmp->next && tmp->id != id)
    tmp = tmp->next;
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
