/*
** incantation2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Wed Jun 21 13:45:08 2017 Martin Alais
** Last update Wed Jun 21 17:40:34 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

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

void level_up_2(t_Player *player)
{
	player->inventaire->linemate -= 1;
	player->inventaire->deraumere -= 1;
	player->inventaire->sibur -= 1;
	player->action->is_leveling = false;
	player->level = 3;
	printf("Player %d reach level 3!\n", player->id);
}

t_Player **get_list_level_4(t_Server *server, t_Player *player)
{
	t_Player **tmp2;
	t_Player *tmp;
	int a;

	a = 0;
	tmp2 = my_malloc(sizeof(t_Player *) * 3);
	tmp2[0] = NULL;
	tmp2[1] = NULL;
	tmp2[2] = NULL;
	tmp = server->list_player;
	while (tmp)
	{
		if (tmp->id != player->id && tmp->action->is_leveling == true &&
			tmp->level == 4 && tmp->inventaire->linemate >= 1 &&
			tmp->inventaire->deraumere >= 1 && a < 3 &&
			tmp->inventaire->sibur >= 2 && tmp->inventaire->phiras >= 1)
		{
			tmp2[a] = tmp;
			a += 1;
		}
		tmp = tmp->next;
	}
	return (tmp2);
}
