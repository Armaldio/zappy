/*
** level5_end.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Wed Jun 28 11:16:34 2017 Martin Alais
** Last update Sun Jul  2 15:04:45 2017 martin alais
*/

#include "zappy.h"

bool	error_level_5(t_Player *player, t_Server *server)
{
  if (player->action->friend_list[0] == 0 ||
      player->action->friend_list[1] == 0 ||
      player->action->friend_list[2] == 0)
    {
      player->action->is_leveling = false;
      player->action->try_level_up = false;
      player->action->friend_list[0] = 0;
      player->action->friend_list[1] = 0;
      player->action->friend_list[2] = 0;
      stok_answer(player, "ko\n");
      event_endI(server, player);
      return (true);
    }
  return (false);
}

void		valide_level5(t_Server *server, t_Player *player)
{
  t_Player	*player2;
  int		a;

  a = 0;
  server->world->map[player->pos.x][player->pos.y]->linemate = 0;
  server->world->map[player->pos.x][player->pos.y]->deraumere = 0;
  server->world->map[player->pos.x][player->pos.y]->sibur = 0;
  server->world->map[player->pos.x][player->pos.y]->mendiane = 0;
  player->level = 6;
  printf("Player %d reach level 6!\n", player->id);
  stok_answer(player, "Current level: 6\n");
  while (a < 3)
    {
      player2 = get_Player(player->action->friend_list[a],
			   server->list_player);
      player2->level = 6;
      printf("Player %d reach level 6!\n", player2->id);
      send_message(player2, "Curent level: 6\n");
      a += 1;
    }
  event_endI(server, player);
}

void		invalide_level5(t_Server *server, t_Player *player)
{
  int		a;
  t_Player	*player2;

  a = 0;
  while (a < 3)
    {
      player2 = get_Player(player->action->friend_list[0],
			   server->list_player);
      stok_answer(player2, "ko\n");
      a += 1;
    }
  stok_answer(player, "ko\n");
  event_endI(server, player);
}

void	reset_level5(t_Player *player)
{
  player->action->is_leveling = false;
  player->action->try_level_up = false;
  player->action->friend_list[0] = 0;
  player->action->friend_list[1] = 0;
  player->action->friend_list[2] = 0;
}

void		end_level5(t_Server *server, t_Player *player)
{
  t_Player	*player2;
  int		a;
  
  a = 0;
  if (error_level_5(player, server))
    return ;
  if (compare_tab(build_tab_5(), build_tab(server, player)) &&
      nbr_case(server, player) == 4 && player->action->is_leveling == false)
    valide_level5(server, player);
  else
    invalide_level5(server, player);
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
  reset_level5(player);
}
