/*
** incantation.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Tue Jun 20 09:44:39 2017 loic1.doyen@epitech.eu
** Last update Fri Jun 23 16:25:27 2017 Martin Alais
*/

#include "Incantation.h"

// level 1 a 2
void incan_1(t_Server *server, t_Player *player)
{
	(void) server;
	if (player->inventaire->linemate >= 1)
	{
		player->inventaire->linemate -= 1;
		player->level = 2;
		player->action->is_leveling = false;
		printf("Player %d reach level 2!\n", player->id);
		player->isGraphic == true ? send_message_pie(player, 1) :
	  stok_answer(player, "ok\n");
	}
}

// level 2 a 3
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
			tmp->isGraphic == true ? send_message_pie(tmp, 1) :
		stok_answer(tmp, "ok\n");
			player->isGraphic == true ? send_message_pie(player, 1) :
		stok_answer(player, "ok\n");
		}
	}
}

// level 3 a 4
void incan_3(t_Server *server, t_Player *player)
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
			level_up_3(player);
			level_up_3(tmp);
			tmp->isGraphic == true ? send_message_pie(tmp, 1) :
	    stok_answer(tmp, "ok\n");
	  	player->isGraphic == true ? send_message_pie(player, 1) :
	    stok_answer(player, "ok\n");
		}
	}
}

// level 4 a 5
void incan_4(t_Server *server, t_Player *player)
{
	t_Player *tmp;
	t_Player **tmp2;

	tmp = server->list_player;
	if (tmp->inventaire->linemate >= 1 && tmp->inventaire->deraumere >= 1 &&
		tmp->inventaire->sibur >= 2 && tmp->inventaire->phiras >= 1)
	if (check_nbr_at_level(server, 4) >= 4)
	{
		tmp2 = get_list_level_4(server, player);
		if (tmp2[0] != NULL && tmp2[1] != NULL && tmp2[2] != NULL)
		{
			player->inventaire->linemate -= 1;
			player->inventaire->deraumere -= 1;
			player->inventaire->sibur -= 2;
			player->inventaire->phiras -= 1;
			player->action->is_leveling = false;
			player->level = 5;
			printf("Player %d reach level 5!\n", player->id);
			player->isGraphic == true ? send_message_pie(player, 1) :
	    stok_answer(player, "ok\n");
			level_up_4(tmp2, server);
			free(tmp2);
		}
	}
}

// level 5 a 6
void incan_5(t_Server *server, t_Player *player)
{
	t_Player *tmp;
	t_Player **tmp2;

	tmp = server->list_player;
	if (tmp->inventaire->linemate >= 1 && tmp->inventaire->deraumere >= 2 &&
		tmp->inventaire->sibur >= 1 && tmp->inventaire->mendiane >= 3)
	if (check_nbr_at_level(server, 5) >= 4)
	{
		tmp2 = get_list_level_5(server, player);
		if (tmp2[0] != NULL && tmp2[1] != NULL && tmp2[2] != NULL)
		{
			player->inventaire->linemate -= 1;
			player->inventaire->deraumere -= 2;
			player->inventaire->sibur -= 1;
			player->inventaire->mendiane -= 3;
			player->action->is_leveling = false;
			player->level = 6;
			printf("Player %d reach level 6!\n", player->id);
			player->isGraphic == true ? send_message_pie(player, 1) :
	  	stok_answer(player, "ok\n");
			level_up_5(tmp2, server);
			free(tmp2);
		}
	}
}
