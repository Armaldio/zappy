/*
** level7.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:31:38 2017 Martin Alais
** Last update Mon Jun 26 14:02:09 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

void healp_incan_7(t_Player *player)
{
	player->inventaire->linemate -= 2;
	player->inventaire->deraumere -= 2;
	player->inventaire->sibur -= 2;
	player->inventaire->mendiane -= 2;
	player->inventaire->phiras -= 2;
	player->inventaire->thystane -= 2;
	player->action->is_leveling = false;
}

void help_init_level_7(t_Player **tmp2)
{
	tmp2[0] = NULL;
	tmp2[1] = NULL;
	tmp2[2] = NULL;
	tmp2[3] = NULL;
	tmp2[4] = NULL;
}

void level_up_7(t_Player **player, t_Server *server)
{
	int a;

  (void)server;
	a = 0;
	while (a < 5)
	{
		player[a]->inventaire->linemate -= 2;
		player[a]->inventaire->deraumere -= 2;
		player[a]->inventaire->sibur -= 2;
		player[a]->inventaire->mendiane -= 2;
		player[a]->inventaire->phiras -= 2;
		player[a]->inventaire->thystane -= 2;
		player[a]->action->is_leveling = false;
		player[a]->level = 8;
		printf("Player %d reach level 8!\n", player[a]->id);
		stok_answer(player[a], "ok\n");
		a += 1;
	}
}

t_Player **get_list_level_7(t_Server *server, t_Player *player)
{
	t_Player **tmp2;
	t_Player *tmp;
	int a;

	a = 0;
	tmp2 = my_malloc(sizeof(t_Player *) * 5);
	help_init_level_7(tmp2);
	tmp = server->list_player;
	while (tmp)
	{
		if (tmp->id != player->id && tmp->action->is_leveling == true &&
			tmp->level == 7 && a < 5 && tmp->inventaire->linemate >= 2 &&
			tmp->inventaire->deraumere >= 2 && tmp->inventaire->sibur >= 2 &&
			tmp->inventaire->mendiane >= 2 && tmp->inventaire->phiras >= 2 &&
			tmp->inventaire->thystane >= 1)
		{
			tmp2[a] = tmp;
			a += 1;
		}
		tmp = tmp->next;
	}
	return (tmp2);
}

void incan_7(t_Server *server, t_Player *player)
{
	t_Player *tmp;
	t_Player **tmp2;

	tmp = server->list_player;
	if (tmp->inventaire->linemate >= 2 && tmp->inventaire->deraumere >= 2 &&
		tmp->inventaire->sibur >= 2 && tmp->inventaire->mendiane >= 2 &&
		tmp->inventaire->phiras >= 2 && tmp->inventaire->thystane >= 1)
	if (check_nbr_at_level(server, 7) >= 4)
	{
		tmp2 = get_list_level_7(server, player);
		if (tmp2[0] != NULL && tmp2[1] != NULL &&
			tmp2[2] != NULL && tmp2[3] != NULL && tmp2[4] != NULL)
		{
			healp_incan_7(player);
			player->level = 8;
			printf("Player %d reach level 8!\n", player->id);
			stok_answer(player, "ok\n");
			level_up_7(tmp2, server);
			free(tmp2);
		}
	}
}
