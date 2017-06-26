/*
** level1.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:12:47 2017 Martin Alais
** Last update Mon Jun 26 13:14:10 2017 Martin Alais
*/

#include "zappy.h"

void incan_1(t_Server *server, t_Player *player)
{
	(void) server;
	if (player->inventaire->linemate >= 1)
	{
		player->inventaire->linemate -= 1;
		player->level = 2;
		player->action->is_leveling = false;
		printf("Player %d reach level 2!\n", player->id);
		stok_answer(player, "ok\n");
	}
}
