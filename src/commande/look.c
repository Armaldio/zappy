/*
** command_look.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Tue Jun 20 11:55:27 2017 loic1.doyen@epitech.eu
** Last update Thu Jun 29 15:32:47 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

static char message[4096];

static char *to_print[] = {
  " food",
  "",
  "",
  " linemate",
  " deraumere",
  " sibur",
  " mendiane",
  " phiras",
  " thystane"
};

void		t_backward(t_Player *tmp, int i, int y, t_Server *server)
{
  int		x;
  int		j;
  int		it;
  t_Mapu	 *current;

  x = ((tmp->pos.x - i + y) + server->world->height) % server->world->height;
  j = ((tmp->pos.y - y) + server->world->width) % server->world->width;
  current = (t_Mapu *)server->world->map[x][j];
  it = 0;
  while (it < 9)
    {
      if (it != 2 && it != 3)
	{
	  if (current->tab[it] >= 1)
	    strcat(message, to_print[it]);
	}
      it++;
    }
  if (i != tmp->level * 2 && strcat(message, ",")) {};
}

void		t_forward(t_Player *tmp, int i, int y, t_Server *server)
{
  int		x;
  int		j;
  int		it;
  t_Mapu	*current;

  if (tmp->gaze == DOWN)
    {
      t_backward(tmp, i, y, server);
      return ;
    }
  x = ((tmp->pos.x + i - y) + server->world->height) % server->world->height;
  j = ((tmp->pos.y + y) + server->world->width) % server->world->width;
  current = (t_Mapu *)server->world->map[x][j];
  it = 0;
  while (it < 9)
    {
      if (it != 2 && it != 3)
	{
	  if (current->tab[it] >= 1)
	    strcat(message, to_print[it]);
	}
      it++;
    }
  if (i != tmp->level * 2 && strcat(message, ",")) {};
}

void		t_right(t_Player *tmp, int i, int y, t_Server *server)
{
  int		x;
  int		j;
  int		it;
  t_Mapu 	*current;

  x = ((tmp->pos.x + y) + server->world->height) % server->world->height;
  j = ((tmp->pos.y - i + y) + server->world->width) % server->world->width;
  current = (t_Mapu *)server->world->map[x][j];
  it = 0;
  while (it < 9)
    {
      if (it != 2 && it != 3)
	{
	  if (current->tab[it] >= 1)
	    strcat(message, to_print[it]);
	}
      it++;
    }
  if (i != tmp->level * 2 && strcat(message, ",")) {};
}

void		t_left(t_Player *tmp, int i, int y, t_Server *server)
{
  int		x;
  int		j;
  int		it;
  t_Mapu	*current;

  if (tmp->gaze == RIGHT)
    {
      t_right(tmp, i, y, server);
      return ;
    }
  x = ((tmp->pos.x + i - y) + server->world->height) % server->world->height;
  j = ((tmp->pos.y - y) + server->world->width) % server->world->width;
  current = (t_Mapu *)server->world->map[x][j];
  it = 0;
  while (it < 9)
    {
      if (it != 2 && it != 3)
	{
	  if (current->tab[it] >= 1)
	    strcat(message, to_print[it]);
	}
      it++;
    }
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
