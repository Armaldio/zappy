/*
** commande_graphic.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/graphic/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 15:55:33 2017 Martin Alais
** Last update Thu Jun 22 17:01:33 2017 hamza hammouche
*/

#include "zappy.h"
#include "Graphic.h"

void commande_graphic(t_Player *player, t_Server *server, char *data)
{
	(void) player;
	(void) data;
  server->isGraphic = true;
}
