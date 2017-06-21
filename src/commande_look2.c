/*
** commande_look2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Tue Jun 20 17:37:56 2017 Martin Alais
** Last update Tue Jun 20 17:38:56 2017 Martin Alais
*/

#include "zappy.h"

void start_look(t_Server *server, t_Player *tmp, char *data)
{
	(void) data;
	start_action(server, tmp, 7);
}
