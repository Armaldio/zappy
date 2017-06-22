/*
** incantation4.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Wed Jun 21 17:37:05 2017 Martin Alais
** Last update Wed Jun 21 18:17:57 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

// level 6 a 7
void incan_6(t_Server *server, t_Player *player)
{
	t_Player *tmp;
	t_Player **tmp2;

	tmp = server->list_player;
	if (tmp->inventaire->linemate >= 1 && tmp->inventaire->deraumere >= 2 &&
		tmp->inventaire->sibur >= 3 && tmp->inventaire->phiras >= 1)
	if (check_nbr_at_level(server, 6) >= 6)
	{
		tmp2 = get_list_level_6(server, player);
		if (tmp2[0] != NULL && tmp2[1] != NULL &&
			tmp2[2] != NULL && tmp2[3] != NULL && tmp2[4] != NULL)
		{
			player->inventaire->linemate -= 1;
			player->inventaire->deraumere -= 2;
			player->inventaire->sibur -= 3;
			player->inventaire->phiras -= 1;
			player->action->is_leveling = false;
			player->level = 7;
			printf("Player %d reach level 7!\n", player->id);
			send_message(player->fd, "OK\n");
			level_up_6(tmp2);
			free(tmp2);
		}
	}
}

// level 7 a 8
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
			send_message(player->fd, "OK\n");
			level_up_7(tmp2);
			free(tmp2);
		}
	}
}

t_Player **get_list_level_5(t_Server *server, t_Player *player)
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
			tmp->level == 5 && a < 3 && tmp->inventaire->linemate >= 1 &&
			tmp->inventaire->deraumere >= 2 && tmp->inventaire->sibur >= 1 &&
			tmp->inventaire->mendiane >= 3)
		{
			tmp2[a] = tmp;
			a += 1;
		}
		tmp = tmp->next;
	}
	return (tmp2);
}

t_Player **get_list_level_6(t_Server *server, t_Player *player)
{
	t_Player **tmp2;
	t_Player *tmp;
	int a;

	a = 0;
	tmp2 = my_malloc(sizeof(t_Player *) * 5);
	tmp2[0] = NULL;
	tmp2[1] = NULL;
	tmp2[2] = NULL;
	tmp2[3] = NULL;
	tmp2[4] = NULL;
	tmp = server->list_player;
	while (tmp)
	{
		if (tmp->id != player->id && tmp->action->is_leveling == true &&
			tmp->level == 6 && a < 5 && tmp->inventaire->linemate >= 1 &&
			tmp->inventaire->deraumere >= 2 && tmp->inventaire->sibur >= 3 &&
			tmp->inventaire->phiras >= 1)
		{
			tmp2[a] = tmp;
			a += 1;
		}
		tmp = tmp->next;
	}
	return (tmp2);
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
