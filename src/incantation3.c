/*
** incantation3.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Wed Jun 21 17:35:52 2017 Martin Alais
** Last update Fri Jun 23 16:26:22 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

void level_up_3(t_Player *player)
{
	player->inventaire->linemate -= 2;
	player->inventaire->phiras -= 2;
	player->inventaire->sibur -= 1;
	player->action->is_leveling = false;
	player->level = 4;
	printf("Player %d reach level 4!\n", player->id);
}

void level_up_4(t_Player **player, t_Server *server)
{
	int a;

  (void)server;
	a = 0;
	while (a < 3)
	{
		player[a]->inventaire->linemate -= 1;
		player[a]->inventaire->deraumere -= 1;
		player[a]->inventaire->sibur -= 2;
		player[a]->inventaire->phiras -= 1;
		player[a]->action->is_leveling = false;
		player[a]->level = 5;
		printf("Player %d reach level 5!\n", player[a]->id);
		player[a]->isGraphic == true ? send_message_pie(player[a], 1) :
	  stok_answer(player[a], "ok\n");
		a += 1;
	}
}

void level_up_5(t_Player **player, t_Server *server)
{
	int a;

  (void)server;
	a = 0;
	while (a < 3)
	{
		player[a]->inventaire->linemate -= 1;
		player[a]->inventaire->deraumere -= 2;
		player[a]->inventaire->sibur -= 1;
		player[a]->inventaire->mendiane -= 3;
		player[a]->action->is_leveling = false;
		player[a]->level = 6;
		printf("Player %d reach level 6!\n", player[a]->id);
		player[a]->isGraphic == true ? send_message_pie(player[a], 1) :
	  stok_answer(player[a], "ok\n");
		a += 1;
	}
}

void level_up_6(t_Player **player, t_Server *server)
{
	int a;

  (void)server;
	a = 0;
	while (a < 5)
	{
		player[a]->inventaire->linemate -= 1;
		player[a]->inventaire->deraumere -= 2;
		player[a]->inventaire->sibur -= 3;
		player[a]->inventaire->phiras -= 1;
		player[a]->action->is_leveling = false;
		player[a]->level = 7;
		printf("Player %d reach level 7!\n", player[a]->id);
		player[a]->isGraphic == true ? send_message_pie(player[a], 1) :
	  stok_answer(player[a], "ok\n");
		a += 1;
	}
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
		player[a]->isGraphic == true ? send_message_pie(player[a], 1) :
	  stok_answer(player[a], "ok\n");
		a += 1;
	}
}
