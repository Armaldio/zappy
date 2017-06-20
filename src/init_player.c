/*
** init_player.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Tue Jun 20 14:34:17 2017 Martin Alais
** Last update Tue Jun 20 14:35:08 2017 Martin Alais
*/

#include "zappy.h"

void init_player2(t_Player *new)
{
	new->level = 1;
	init_inventaire(new);
	init_action(new);
	ini_waiting_line(new);
	new->next = NULL;

}
