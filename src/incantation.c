/*
** incantation.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Tue Jun 20 09:44:39 2017 loic1.doyen@epitech.eu
** Last update Wed Jun 21 14:48:46 2017 Martin Alais
*/

#include "Incantation.h"

void incan_1(t_Server *server, t_Player *player)
{
	(void) server;
	if (player->inventaire->linemate >= 1)
	{
		player->inventaire->linemate -= 1;
		player->level = 2;
		player->action->is_leveling = false;
		printf("Player %d reach level 2!\n", player->id);
		send_message(player->fd, "OK\n");
	}
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
			send_message(tmp->fd, "OK\n");
			send_message(player->fd, "OK\n");
		}
	}
}

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
			level_up_3(tmp);
			level_up_3(player);
			send_message(tmp->fd, "OK\n");
			send_message(player->fd, "OK\n");
		}
	}
}

void incan_4(t_Server *server, t_Player *player)
{
	t_Player *tmp;
	t_Player *tmp2[3];

	tmp = server->list_player;
	if (tmp->inventaire->linemate >= 1 && tmp->inventaire->deraumere >= 1 &&
		tmp->inventaire->sibur >= 2 && tmp->inventaire->phiras >= 1)
	if (check_nbr_at_level(server, 4) >= 4)
	{
		tmp2 = get_list_level_4(server, player);
		if (is_ready_to_up_3(tmp, player) == true)
		{
			level_up_3(tmp);
			level_up_3(player);
			send_message(tmp->fd, "OK\n");
			send_message(player->fd, "OK\n");
		}
	}
}

void incan_5(t_Server *server, t_Player *player)
{
	(void) server;
}
