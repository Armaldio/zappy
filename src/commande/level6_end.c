/*
** level6_end.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Wed Jun 28 12:24:30 2017 Martin Alais
** Last update Thu Jun 29 15:52:02 2017 Martin Alais
*/

#include "zappy.h"

bool error_level_6(t_Player *player, t_Server *server)
{
	if (player->action->friend_list[0] == 0 ||
		player->action->friend_list[1] == 0 ||
		player->action->friend_list[2] == 0 ||
		player->action->friend_list[3] == 0 ||
		player->action->friend_list[4] == 0)
		{
			player->action->is_leveling = false;
			player->action->try_level_up = false;
			player->action->friend_list[0] = 0;
			player->action->friend_list[1] = 0;
			player->action->friend_list[2] = 0;
			player->action->friend_list[3] = 0;
			player->action->friend_list[4] = 0;
			stok_answer(player, "ko\n");
			event_endI(server, player);
			return (true);
		}
	return (false);
}

void valide_level6(t_Server *server, t_Player *player)
{
	int a;
	t_Player *player2;

	a = 0;
	server->world->map[player->pos.x][player->pos.y]->linemate = 0;
	server->world->map[player->pos.x][player->pos.y]->deraumere = 0;
	server->world->map[player->pos.x][player->pos.y]->sibur = 0;
	server->world->map[player->pos.x][player->pos.y]->phiras = 0;
	player->level = 7;
	printf("Player %d reach level 7!\n", player->id);
	stok_answer(player, "Current level: 7\n");
	while (a < 5)
	{
		player2 = get_Player(player->action->friend_list[a],
			server->list_player);
		player2->level = 7;
		printf("Player %d reach level 7!\n", player2->id);
		send_message(player2->fd, "Curent level: 7\n");
		a += 1;
	}
	event_endI(server, player);
}

void invalide_level6(t_Server *server, t_Player *player)
{
	int a;
	t_Player *player2;

	a = 0;
	while (a < 5)
	{
		player2 = get_Player(player->action->friend_list[0],
			server->list_player);
		stok_answer(player2, "ko\n");
		a += 1;
	}
	stok_answer(player, "ko\n");
	event_endI(server, player);
}

void reset_level6(t_Player *player)
{
	player->action->is_leveling = false;
	player->action->try_level_up = false;
	player->action->friend_list[0] = 0;
	player->action->friend_list[1] = 0;
	player->action->friend_list[2] = 0;
	player->action->friend_list[3] = 0;
	player->action->friend_list[4] = 0;
}

void end_level6(t_Server *server, t_Player *player)
{
	t_Player *player2;
	int a;

	a = 0;
	if (error_level_6(player, server))
		return ;
	if (compare_tab(build_tab_6(), build_tab(server, player)) &&
	nbr_case(server, player) == 6 && player->action->is_leveling == false)
		valide_level6(server, player);
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
