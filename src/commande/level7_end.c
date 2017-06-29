/*
** level7_end.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Wed Jun 28 13:11:26 2017 Martin Alais
** Last update Thu Jun 29 15:52:23 2017 Martin Alais
*/

#include "zappy.h"

void valide_level7(t_Server *server, t_Player *player)
{
	int a;
	t_Player *player2;

	a = 0;
	server->world->map[player->pos.x][player->pos.y]->linemate = 0;
	server->world->map[player->pos.x][player->pos.y]->deraumere = 0;
	server->world->map[player->pos.x][player->pos.y]->sibur = 0;
	server->world->map[player->pos.x][player->pos.y]->phiras = 0;
	server->world->map[player->pos.x][player->pos.y]->thystane = 0;
	server->world->map[player->pos.x][player->pos.y]->mendiane = 0;
	player->level = 8;
	printf("Player %d reach level 8!\n", player->id);
	stok_answer(player, "Current level: 8\n");
	while (a < 5)
	{
		player2 = get_Player(player->action->friend_list[a],
			server->list_player);
		player2->level = 8;
		printf("Player %d reach level 8!\n", player2->id);
		stok_answer(player2, "ok\n");
		a += 1;
	}
	event_endI(server, player);
}

void end_level7(t_Server *server, t_Player *player)
{
	t_Player *player2;
	int a;

	a = 0;
	if (error_level_6(player, server))
		return ;
	if (compare_tab(build_tab_7(), build_tab(server, player)) &&
	nbr_case(server, player) == 6 && player->action->is_leveling == false)
		valide_level7(server, player);
	else
		invalide_level6(server, player);
	while (a < 5)
	{
		player2 = get_Player(player->action->friend_list[a],
			server->list_player);
		player2->action->is_leveling = false;
		player2->action->try_level_up = false;
		player2->action->friend_list[0] = 0;
		player2->action->friend_list[1] = 0;
		player2->action->friend_list[2] = 0;
		player2->action->friend_list[3] = 0;
		player2->action->friend_list[4] = 0;
		a += 1;
	}
	reset_level6(player);
}
