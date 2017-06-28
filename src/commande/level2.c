/*
** level2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:14:33 2017 Martin Alais
** Last update Wed Jun 28 16:47:02 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

void reset_level2(t_Player *player, t_Player *player2)
{
	player->action->is_leveling = false;
	player->action->try_level_up = false;
	player2->action->is_leveling = false;
	player2->action->try_level_up = false;
	player->action->friend_list[0] = 0;
	player2->action->friend_list[0] = 0;
}

bool repaire_level2(t_Server *server, t_Player *player)
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
		while (tmp && is_ready_to_up_2(tmp, player) == false)
			tmp = tmp->next;
		if (is_ready_to_up_2(tmp, player) == true)
			player->action->friend_list[0] = tmp->id;
		else
		{
			stok_answer(player, "ko\n");
			return (false);
		}
	}
	return (true);
}

void send_else_level2(t_Server *server, t_Player *player)
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

void end_level2(t_Server *server, t_Player *player)
{
	t_Player *player2;
	char data[100];

	if (repaire_level2(server, player) == false)
		return ;
	memset(data, '\0', 100);
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
		sprintf(data, "Current level: %d\n", player2->level);
		send_message(player2->fd, data);
		stok_answer(player, "ok\n");
	}
	else
		send_else_level2(server, player);
	reset_level2(player, player2);
}
