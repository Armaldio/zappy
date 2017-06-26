/*
** level2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:14:33 2017 Martin Alais
** Last update Mon Jun 26 13:19:15 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

bool	is_ready_to_up_2(t_Player *tmp, t_Player *player)
{
	if (tmp->id == player->id || tmp->action->is_leveling == false ||
		tmp->level != 2)
		return (false);
	if (tmp->inventaire->linemate >= 1 && tmp->inventaire->deraumere >= 1 &&
		tmp->inventaire->sibur >= 1)
		return (true);
	return (false);
}

int check_nbr_at_level(t_Server *server, int level)
{
	int nbr;
	t_Player *tmp;

	nbr = 0;
	tmp = server->list_player;
	while (tmp)
	{
		if (tmp->action->is_leveling && tmp->level == level)
			nbr += 1;
		tmp = tmp->next;
	}
	return (nbr);
}

void level_up_2(t_Player *player)
{
	player->inventaire->linemate -= 1;
	player->inventaire->deraumere -= 1;
	player->inventaire->sibur -= 1;
	player->action->is_leveling = false;
	player->level = 3;
	printf("Player %d reach level 3!\n", player->id);
}

void incan_2(t_Server *server, t_Player *player)
{
	t_Player *tmp;

	tmp = server->list_player;
	if (tmp->inventaire->linemate >= 1 && tmp->inventaire->deraumere >= 1 &&
		tmp->inventaire->sibur >= 1)
	if (check_nbr_at_level(server, 2) >= 2)
	{
		while (tmp && is_ready_to_up_2(tmp, player) == false)
			tmp = tmp->next;
		if (is_ready_to_up_2(tmp, player) == true)
		{
			level_up_2(tmp);
			level_up_2(player);
			stok_answer(tmp, "ok\n");
			stok_answer(player, "ok\n");
		}
	}
}
