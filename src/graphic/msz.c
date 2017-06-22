/*
** msz.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/graphic/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 16:01:38 2017 Martin Alais
** Last update Thu Jun 22 16:11:42 2017 Martin Alais
*/

#include "zappy.h"
#include "Graphic.h"

void commande_msz(t_Player *player, t_Server *server, char *data)
{
	char data_send[100];

	(void) data;
	memset(data_send, '\0', 100);
	sprintf(data_send, "msz %d %d\n",
	server->world->width, server->world->height);
	send_message(player->fd, data_send);
}
