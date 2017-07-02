/*
** level6.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:30:03 2017 Martin Alais
** Last update Sun Jul  2 15:06:04 2017 martin alais
*/

#include "zappy.h"
#include "Incantation.h"

t_Player	**get_list_level_6(t_Server *server, t_Player *player)
{
  t_Player	**tmp2;
  t_Player	*tmp;
  int		a;

  a = 0;
  tmp2 = my_malloc(sizeof(t_Player *) * 5);
  tmp2[0] = NULL;
  tmp2[1] = NULL;
  tmp2[2] = NULL;
  tmp2[3] = NULL;
  tmp2[4] = NULL;
  tmp = server->list_player;
  while (tmp)
    {
      if (tmp->id != player->id && tmp->level == 6 && a < 5)
	{
	  tmp2[a] = tmp;
	  a += 1;
	}
      tmp = tmp->next;
    }
  return (tmp2);
}

void	complete_struct6bis(t_Player **tmp2, t_Player *player, int a, int b)
{
  int	c;

  while (a < 5)
    {
      b = 0;
      c = 0;
      while (b < 5)
	{
	  if (b == 0)
	    {
	      tmp2[a]->action->friend_list[b] = player->id;
	      b += 1;
	    }
	  else if (c != a)
	    {
	      tmp2[a]->action->friend_list[b] = tmp2[c]->id;
	      c += 1;
	      b += 1;
	    }
	  else
	    c += 1;
	}
      a += 1;
    }
}

void	complete_struct6(t_Player **tmp2, t_Player *player, bool status)
{
  int	a;
  int	b;

  a = 0;
  while (a < 5)
    {
      player->action->friend_list[a] = tmp2[a]->id;
      send_message(tmp2[a], "Elevation Underway\n");
      a += 1;
    }
  a = 0;
  b = 0;
  complete_struct6bis(tmp2, player, a, b);
  if (status)
    send_message(player, "Elevation Underway\n");
  else
    send_message(player, "ko\n");
}

bool		incan_6bis(t_Server *server, t_Player *player)
{
  t_Player	**tmp2;

  if (check_nbr_at_level(server, player, 6) == 6)
    {
      tmp2 = get_list_level_6(server, player);
      if (tmp2[0] != NULL && tmp2[1] != NULL &&
	  tmp2[2] != NULL && tmp2[3] != NULL && tmp2[4] != NULL)
	{
	  player->action->is_leveling = false;
	  tmp2[0]->action->is_leveling = false;
	  tmp2[1]->action->is_leveling = false;
	  tmp2[2]->action->is_leveling = false;
	  tmp2[3]->action->is_leveling = false;
	  tmp2[4]->action->is_leveling = false;
	  complete_struct6(tmp2, player, false);
	  return (false);
	}
    }
  return (true);
}

void		incan_6(t_Server *server, t_Player *player)
{
  t_Player	**tmp2;

  if (compare_tab(build_tab_6(), build_tab(server, player)) &&
      check_nbr_at_level(server, player, 6) == 6)
    {
      tmp2 = get_list_level_6(server, player);
      if (tmp2[0] != NULL && tmp2[1] != NULL &&
	  tmp2[2] != NULL && tmp2[3] != NULL && tmp2[4] != NULL)
	{
	  player->action->is_leveling = false;
	  tmp2[0]->action->is_leveling = false;
	  tmp2[1]->action->is_leveling = false;
	  tmp2[2]->action->is_leveling = false;
	  tmp2[3]->action->is_leveling = false;
	  tmp2[4]->action->is_leveling = false;
	  complete_struct6(tmp2, player, true);
	  free(tmp2);
	  return ;
	}
      else
	return (clean_player4(player));
    }
  else if (incan_6bis(server, player) == false)
    return ;
  clean_player4(player);
}
