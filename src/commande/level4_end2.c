/*
** level4_end2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Wed Jun 28 19:20:52 2017 Martin Alais
** Last update Sun Jul  2 15:00:27 2017 martin alais
*/

#include "zappy.h"

void		send_message_level4(char *data, t_Player *player, t_Server *server)
{
  int		a;
  t_Player	*tmp;

  a = 0;
  while (a < 3)
    {
      if (player->action->friend_list[a] != 0)
	{
	  tmp = get_Player(player->action->friend_list[a],
			   server->list_player);
	  send_message(tmp, data);
	}
      a += 1;
    }
}

bool	error_level_4(t_Player *player, t_Server *server)
{
  char	data[100];

  memset(data, '\0', 100);
  sprintf(data, "Current level: %d\n", player->level);
  if (player->action->friend_list[0] == 0 ||
      player->action->friend_list[1] == 0 ||
      player->action->friend_list[2] == 0)
    {
      player->action->is_leveling = false;
      player->action->try_level_up = false;
      send_message_level4(data, player, server);
      player->action->friend_list[0] = 0;
      player->action->friend_list[1] = 0;
      player->action->friend_list[2] = 0;
      stok_answer(player, "ko\n");
      event_endI(server, player);
      return (true);
    }
  return (false);
}

int	*build_tab_4()
{
  int	*tab;

  tab = malloc(sizeof(int) * 7);
  tab[0] = 0;
  tab[1] = 1;
  tab[2] = 1;
  tab[3] = 2;
  tab[4] = 0;
  tab[5] = 1;
  tab[6] = 0;
  return (tab);
}

t_Player	**get_list_level_4(t_Server *server, t_Player *player)
{
  t_Player	**tmp2;
  t_Player	*tmp;
  int		a;

  a = 0;
  tmp2 = my_malloc(sizeof(t_Player *) * 3);
  tmp2[0] = NULL;
  tmp2[1] = NULL;
  tmp2[2] = NULL;
  tmp = server->list_player;
  while (tmp)
    {
      if (tmp->id != player->id && tmp->level == 4)
	{
	  tmp2[a] = tmp;
	  a += 1;
	}
      tmp = tmp->next;
    }
  return (tmp2);
}
