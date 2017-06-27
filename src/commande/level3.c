/*
** level3.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:19:36 2017 Martin Alais
** Last update Mon Jun 26 16:28:45 2017 hamza hammouche
*/

#include "zappy.h"
#include "Incantation.h"

bool	is_ready_to_up_3(t_Player *tmp, t_Player *player)
{
	if (tmp->id == player->id || tmp->action->is_leveling == false ||
		tmp->level != 3)
		return (false);
	if (tmp->inventaire->linemate >= 2 && tmp->inventaire->phiras >= 2 &&
		tmp->inventaire->sibur >= 1)
		return (true);
	return (false);
}

void	level_up_3(t_Server *server, t_Player *player)
{
	player->inventaire->linemate -= 2;
	player->inventaire->phiras -= 2;
	player->inventaire->sibur -= 1;
	player->action->is_leveling = false;
	player->level = 4;
	printf("Player %d reach level 4!\n", player->id);
  event_endI(server, player);
}

void	incan_3(t_Server *server, t_Player *player)
{
	t_Player *tmp;

	tmp = server->list_player;
	if (tmp->inventaire->linemate >= 2 && tmp->inventaire->phiras >= 2 &&
		tmp->inventaire->sibur >= 1)
	if (check_nbr_at_level(server, 3) >= 2)
	{
		while (tmp && is_ready_to_up_3(tmp, player) == false)
			tmp = tmp->next;
		if (is_ready_to_up_3(tmp, player) == true)
		{
			level_up_3(server, player);
			level_up_3(server, tmp);
			stok_answer(tmp, "ok\n");
			stok_answer(player, "ok\n");
		}
	}
}
