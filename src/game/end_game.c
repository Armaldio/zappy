/*
** end_game.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/game/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 12:24:38 2017 Martin Alais
** Last update Tue Jun 27 19:14:26 2017 Martin Alais
*/

#include "zappy.h"

t_team	*check_team_win(t_Server *serv)
{
  t_team *tmp;
  t_Player *ptmp;
  int				i;

  tmp = serv->list_teams;
  while (tmp)
    {
      i = 0;
      ptmp = serv->list_player;
      while (ptmp)
        {
          if (tmp->id == ptmp->teamId && ptmp->level >= 8)
    				i++;
          ptmp = ptmp->next;
        }
      if (i >= 6)
				return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void send_winner(t_graphic *head, t_team *winner)
{
  t_graphic *tmp;
  char			buff[512];

  tmp = head;
  while (tmp)
    {
      sprintf(buff, "seg %s\n", winner->name);
      send_message(tmp->fd, buff);
      tmp = tmp->next;
    }
}

bool end_game(t_Server *serv)
{
  t_team *winner;

  if ((winner = check_team_win(serv)) == NULL)
    return (false);
  send_winner(serv->list_graphic, winner);
  exit(1);
  return (true);
}
