/*
** smg.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/graphic/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Fri Jun 23 11:58:46 2017 Martin Alais
** Last update Fri Jun 23 19:33:29 2017 Martin Alais
*/

#include "zappy.h"
#include "Graphic.h"

void commande_smg(t_graphic *player, char *data)
{
	send_message(player->fd, data);
}

void commande_smg_all(t_Server *server, char *data)
{
	t_Player *player;

	player = server->list_player;
	while (player)
	{
		send_message(player->fd, data);
		player = player->next;
	}
}
