/*
** command_look.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Tue Jun 20 11:55:27 2017 loic1.doyen@epitech.eu
** Last update Tue Jun 27 11:54:41 2017 loic1.doyen@epitech.eu
*/

#include "zappy.h"
#include "Incantation.h"

static char message[4096];

void	t_backward(t_Player *tmp, int i, int y, t_Server *server)
{
  int	x;
  int	j;

  x = ((tmp->pos.x - i + y) + server->world->height) % server->world->height;
  j = ((tmp->pos.y - y) + server->world->width) % server->world->width;
  if (server->world->map[x][j]->food >= 1)
    strcat(message, " food");
  if (server->world->map[x][j]->deraumere >= 1)
    strcat(message, " deraumere");
  if (server->world->map[x][j]->linemate >= 1)
    strcat(message, " linemate");
  if (server->world->map[x][j]->mendiane >= 1)
    strcat(message, " mendiane");
  if (server->world->map[x][j]->phiras >= 1)
    strcat(message, " phiras");
  if (server->world->map[x][j]->sibur >= 1)
    strcat(message, " sibur");
  if (server->world->map[x][j]->thystane >= 1)
    strcat(message, " thystane");
  if (i != tmp->level * 2 && strcat(message, ",")) {};
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
  if (server->world->map[x][j]->food >= 1)
    strcat(message, " food");
  if (server->world->map[x][j]->deraumere >= 1)
    strcat(message, " deraumere");
  if (server->world->map[x][j]->linemate >= 1)
    strcat(message, " linemate");
  if (server->world->map[x][j]->mendiane >= 1)
    strcat(message, " mendiane");
  if (server->world->map[x][j]->phiras >= 1)
    strcat(message, " phiras");
  if (server->world->map[x][j]->sibur >= 1)
    strcat(message, " sibur");
  if (server->world->map[x][j]->thystane >= 1)
    strcat(message, " thystane");
  if (i != tmp->level * 2 && strcat(message, ",")) {};
}

void	t_right(t_Player *tmp, int i, int y, t_Server *server)
{
  int	x;
  int	j;

  x = ((tmp->pos.x + y) + server->world->height) % server->world->height;
  j = ((tmp->pos.y - i + y) + server->world->width) % server->world->width;
  if (server->world->map[x][j]->food >= 1)
    strcat(message, " food");
  if (server->world->map[x][j]->deraumere >= 1)
    strcat(message, " deraumere");
  if (server->world->map[x][j]->linemate >= 1)
    strcat(message, " linemate");
  if (server->world->map[x][j]->mendiane >= 1)
    strcat(message, " mendiane");
  if (server->world->map[x][j]->phiras >= 1)
    strcat(message, " phiras");
  if (server->world->map[x][j]->sibur >= 1)
    strcat(message, " sibur");
  if (server->world->map[x][j]->thystane >= 1)
    strcat(message, " thystane");
  if (i != tmp->level * 2 && strcat(message, ",")) {};
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
  if (server->world->map[x][j]->food >= 1)
    strcat(message, " food");
  if (server->world->map[x][j]->deraumere >= 1)
    strcat(message, " deraumere");
  if (server->world->map[x][j]->linemate >= 1)
    strcat(message, " linemate");
  if (server->world->map[x][j]->mendiane >= 1)
    strcat(message, " mendiane");
  if (server->world->map[x][j]->phiras >= 1)
    strcat(message, " phiras");
  if (server->world->map[x][j]->sibur >= 1)
    strcat(message, " sibur");
  if (server->world->map[x][j]->thystane >= 1)
    strcat(message, " thystane");
  if (i != tmp->level * 2 && strcat(message, ",")) {};
}

int		command_look(int id, t_Server *server, char *data)
{
  t_Player	*tmp;
  int		i;
  int		y;

  tmp = get_Player(id, server->list_player);
  start_look(server, tmp, data);
  memset(message, 0, 4096);
  strcpy(message, "[ player");
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
  strcat(message, " ]\n");
  stok_answer(tmp, message);
  return (0);
}
