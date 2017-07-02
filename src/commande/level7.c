/*
** level7.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:31:38 2017 Martin Alais
** Last update Sun Jul  2 15:09:57 2017 martin alais
*/

#include "zappy.h"
#include "Incantation.h"

int	*build_tab_7()
{
  int	*tab;
  
  tab = malloc(sizeof(int) * 7);
  tab[0] = 0;
  tab[1] = 2;
  tab[2] = 2;
  tab[3] = 2;
  tab[4] = 2;
  tab[5] = 2;
  tab[6] = 1;
  return (tab);
}

void help_init_level_7(t_Player **tmp2)
{
  tmp2[0] = NULL;
  tmp2[1] = NULL;
  tmp2[2] = NULL;
  tmp2[3] = NULL;
  tmp2[4] = NULL;
}

t_Player	**get_list_level_7(t_Server *server, t_Player *player)
{
  t_Player	**tmp2;
  t_Player	*tmp;
  int		a;

  a = 0;
  tmp2 = my_malloc(sizeof(t_Player *) * 5);
  help_init_level_7(tmp2);
  tmp = server->list_player;
  while (tmp)
    {
      if (tmp->id != player->id && tmp->level == 7 && a < 5)
	{
	  tmp2[a] = tmp;
	  a += 1;
	}
      tmp = tmp->next;
    }
  return (tmp2);
}

bool		incan_7bis(t_Server *server, t_Player *player)
{
  t_Player	**tmp2;

  if (check_nbr_at_level(server, player, 6) == 6)
    {
      tmp2 = get_list_level_7(server, player);
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

void		incan_7(t_Server *server, t_Player *player)
{
  t_Player	**tmp2;
	
  if (compare_tab(build_tab(server, player), build_tab_7()) &&
      check_nbr_at_level(server, player, 7) == 6)
    {
      tmp2 = get_list_level_7(server, player);
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
  else if (incan_7bis(server, player) == false)
    return ;
  clean_player4(player);
}
