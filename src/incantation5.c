/*
** incantation5.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Wed Jun 21 17:42:04 2017 Martin Alais
** Last update Wed Jun 21 17:50:01 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

void healp_incan_7(t_Player *player)
{
	player->inventaire->linemate -= 2;
	player->inventaire->deraumere -= 2;
	player->inventaire->sibur -= 2;
	player->inventaire->mendiane -= 2;
	player->inventaire->phiras -= 2;
	player->inventaire->thystane -= 2;
	player->action->is_leveling = false;
}

void help_init_level_7(t_Player **tmp2)
{
	tmp2[0] = NULL;
	tmp2[1] = NULL;
	tmp2[2] = NULL;
	tmp2[3] = NULL;
	tmp2[4] = NULL;
}
