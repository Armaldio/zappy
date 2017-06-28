/*
** level2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:14:33 2017 Martin Alais
** Last update Wed Jun 28 10:51:45 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

int *build_tab_2()
{
	int *tab;
	tab = malloc(sizeof(int) * 7);
	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 1;
	tab[3] = 1;
	tab[4] = 0;
	tab[5] = 0;
	tab[6] = 0;
	return (tab);
}

bool	is_ready_to_up_2(t_Player *tmp, t_Player *player)
{
	if (tmp->id != player->id && tmp->action->is_leveling == true &&
		tmp->level == 2)
		return (true);
	return (false);
}

void incan_2(t_Server *server, t_Player *player)
{
	t_Player *tmp;

	tmp = server->list_player;
	if (compare_tab(build_tab_2(), build_tab(server, player)) &&
		nbr_case_rdy(server, player) == 2)
	{
		while (tmp && is_ready_to_up_2(tmp, player) == false)
			tmp = tmp->next;
		if (is_ready_to_up_2(tmp, player) == true)
		{
			player->action->is_leveling = false;
			tmp->action->is_leveling = false;
			player->action->friend_list[0] = tmp->id;
			tmp->action->friend_list[0] = player->id;
		}
	}
}

void reset_level2(t_Player *player, t_Player *player2)
{
	player->action->is_leveling = false;
	player->action->try_level_up = false;
	player2->action->is_leveling = false;
	player2->action->try_level_up = false;
	player->action->friend_list[0] = 0;
	player2->action->friend_list[0] = 0;
}

void end_level2(t_Server *server, t_Player *player)
{
	t_Player *player2;

	player2 = get_Player(player->action->friend_list[0], server->list_player);
	if (compare_tab(build_tab_2(), build_tab(server, player)) &&
	nbr_case(server, player) == 2 && player->action->is_leveling == false)
	{
		server->world->map[player->pos.x][player->pos.y]->linemate = 0;
		server->world->map[player->pos.x][player->pos.y]->deraumere = 0;
		server->world->map[player->pos.x][player->pos.y]->sibur = 0;
		player->level = 3;
		player2->level = 3;
		printf("Player %d reach level 3!\n", player->id);
		printf("Player %d reach level 3!\n", player2->id);
		event_endI(server, player);
		stok_answer(player, "ok\n");
		stok_answer(player2, "ok\n");
	}
	else
	{
		event_endI(server, player);
		stok_answer(player, "ko\n");
		stok_answer(player2, "ok\n");
	}
	reset_level2(player, player2);
}
