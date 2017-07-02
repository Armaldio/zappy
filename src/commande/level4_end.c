/*
** level4_end.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Wed Jun 28 11:10:39 2017 Martin Alais
** Last update Sun Jul  2 14:59:06 2017 martin alais
*/

#include "zappy.h"

void		valide_level4(t_Server *server, t_Player *player)
{
  t_Player	*player2;
  int		a;

  a = 0;
  server->world->map[player->pos.x][player->pos.y]->linemate = 0;
  server->world->map[player->pos.x][player->pos.y]->deraumere = 0;
  server->world->map[player->pos.x][player->pos.y]->sibur = 0;
  server->world->map[player->pos.x][player->pos.y]->phiras = 0;
  player->level = 5;
  printf("Player %d reach level 5!\n", player->id);
  stok_answer(player, "Current level 5\n");
  while (a < 3)
    {
      player2 = get_Player(player->action->friend_list[a],
			   server->list_player);
      player2->level = 5;
      send_message(player2, "Current level: 5\n");
      printf("Player %d reach level 5!\n", player2->id);
      a += 1;
    }
  event_endI(server, player);
}

void		invalide_level4(t_Server *server, t_Player *player)
{
  t_Player	*player2;
  int		a;

  a = 0;
  while (a < 3)
    {
      player2 = get_Player(player->action->friend_list[a],
			   server->list_player);
      send_message(player2, "Current level: 4\n");
      a += 1;
    }
  stok_answer(player, "ko\n");
  event_endI(server, player);
}

void	reset_level4(t_Player *player)
{
  player->action->is_leveling = false;
  player->action->try_level_up = false;
  player->action->friend_list[0] = 0;
  player->action->friend_list[1] = 0;
  player->action->friend_list[2] = 0;
}

void		repair_level4(t_Server *server, t_Player * player)
{
  t_Player	**tmp2;

  if (player->action->friend_list[0] == 0 &&
      check_nbr_at_level(server, player, 4) == 4)
    {
      tmp2 = get_list_level_4(server, player);
      if (tmp2[0] != NULL && tmp2[1] != NULL && tmp2[2] != NULL)
	{
	  player->action->friend_list[0] = tmp2[0]->id;
	  player->action->friend_list[0] = tmp2[1]->id;
	  player->action->friend_list[0] = tmp2[2]->id;
	}
      free (tmp2);
    }
}

void		end_level4(t_Server *server, t_Player *player)
{
  t_Player	*player2;
  int		a;

  a = 0;
  repair_level4(server, player);
  if (error_level_4(player, server))
    return;
  if (compare_tab(build_tab_4(), build_tab(server, player)) &&
      nbr_case(server, player) == 4 && player->action->is_leveling == false)
    valide_level4(server, player);
  else
    invalide_level4(server, player);
  while (a < 3)
    {
      player2 = get_Player(player->action->friend_list[a],
			   server->list_player);
      player2->action->is_leveling = false;
      player2->action->try_level_up = false;
      player2->action->friend_list[0] = 0;
      player2->action->friend_list[1] = 0;
      player2->action->friend_list[2] = 0;
      a += 1;
    }
  reset_level4(player);
}
