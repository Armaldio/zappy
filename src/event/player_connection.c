/*
** player_connection.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/event/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Sat Jun 24 11:31:38 2017 Martin Alais
** Last update Sat Jun 24 11:38:54 2017 Martin Alais
*/

#include "Event.h"

void send_all_player(t_Server *server, t_graphic *graphic)
{
	t_Player *player;

	player = server->list_player;
	while (player)
	{
		commande_pnw(server, player, graphic);
		player = player->next;
	}
}
