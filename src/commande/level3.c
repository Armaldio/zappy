/*
** level3.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:19:36 2017 Martin Alais
** Last update Wed Jun 28 17:49:14 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

void reset_level3(t_Player *player, t_Player *player2)
{
	player->action->is_leveling = false;
	player->action->try_level_up = false;
	player2->action->is_leveling = false;
	player2->action->try_level_up = false;
	player->action->friend_list[0] = 0;
	player2->action->friend_list[0] = 0;
}

bool repaire_level3(t_Server *server, t_Player *player)
{
	t_Player *tmp;

	tmp = server->list_player;
	if (nbr_case(server, player) != 2)
	{
		stok_answer(player, "ko\n");
		return (false);
	}
	if (player->action->friend_list[0] == 0)
	{
		while (tmp && is_ready_to_up_3(tmp, player) == false)
			tmp = tmp->next;
		if (is_ready_to_up_3(tmp, player) == true)
			player->action->friend_list[0] = tmp->id;
		else
		{
			stok_answer(player, "ko\n");
			return (false);
		}
	}
	return (true);
}

void send_else_level3(t_Server *server, t_Player *player)
{
	char data[100];
	t_Player *player2;

	player2 = get_Player(player->action->friend_list[0], server->list_player);
	memset(data, '\0', 100);
	event_endI(server, player);
	sprintf(data, "Current level: %d\n", player2->level);
	stok_answer(player, "ko\n");
	send_message(player2->fd, data);
}

void end_level3(t_Server *server, t_Player *player)
{
	t_Player *player2;
	char data[100];

	if (repaire_level3(server, player) == false)
		return ;
	memset(data, '\0', 100);
	player2 = get_Player(player->action->friend_list[0], server->list_player);
	if (compare_tab(build_tab_3(), build_tab(server, player)) &&
	nbr_case(server, player) == 2 && player->action->is_leveling == false)
	{
		server->world->map[player->pos.x][player->pos.y]->linemate = 0;
		server->world->map[player->pos.x][player->pos.y]->sibur = 0;
		server->world->map[player->pos.x][player->pos.y]->phiras = 0;
		player->level = 4;
		player2->level = 4;
		printf("Player %d reach level 4!\n", player->id);
		printf("Player %d reach level 4!\n", player2->id);
		sprintf(data, "Current level: %d\n", player2->level);
		send_message(player2->fd, data);
		stok_answer(player, "ok\n");
		event_endI(server, player);
	}
	else
		send_else_level3(server, player);
	reset_level3(player, player2);
}
