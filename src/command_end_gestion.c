/*
** zappy.c for zappy in /home/hammouche/Documents/PSU_2016/zappy/src/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Wed Jun 21 16:09:52 2017 hamza hammouche
** Last update Fri Jun 23 14:58:04 2017 Martin Alais
*/

#include "zappy.h"
#include "Team.h"
#include "Incantation.h"

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

void send_winner(t_Player *head, t_team *winner)
{
  t_Player *tmp;
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
  send_winner(serv->list_player, winner);
  exit(1);
  return (true);
}
