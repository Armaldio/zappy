/*
** level4_end.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Wed Jun 28 11:10:39 2017 Martin Alais
** Last update Wed Jun 28 11:11:04 2017 Martin Alais
*/

#include "zappy.h"

bool error_level_4(t_Player *player, t_Server *server)
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

void valide_level4(t_Server *server, t_Player *player)
{
	t_Player *player2;
	int a;

	a = 0;
	server->world->map[player->pos.x][player->pos.y]->linemate = 0;
	server->world->map[player->pos.x][player->pos.y]->deraumere = 0;
	server->world->map[player->pos.x][player->pos.y]->sibur = 0;
	server->world->map[player->pos.x][player->pos.y]->phiras = 0;
	player->level = 5;
	printf("Player %d reach level 5!\n", player->id);
	stok_answer(player, "ok\n");
	while (a < 3)
	{
		player2 = get_Player(player->action->friend_list[a],
			server->list_player);
		player2->level = 5;
		printf("Player %d reach level 5!\n", player2->id);
		stok_answer(player2, "ok\n");
		a += 1;
	}
	event_endI(server, player);
}

void invalide_level4(t_Server *server, t_Player *player)
{
	t_Player *player2;
	int a;

	a = 0;
	while (a < 3)
	{
		player2 = get_Player(player->action->friend_list[a],
			server->list_player);
		stok_answer(player2, "ko\n");
		a += 1;
	}
	stok_answer(player, "ko\n");
	event_endI(server, player);
}

void reset_level4(t_Player *player)
{
	player->action->is_leveling = false;
	player->action->try_level_up = false;
	player->action->friend_list[0] = 0;
	player->action->friend_list[1] = 0;
	player->action->friend_list[2] = 0;
}

void end_level4(t_Server *server, t_Player *player)
{
	t_Player *player2;
	int a;

	a = 0;
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
