/*
** msz.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/graphic/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 16:01:38 2017 Martin Alais
** Last update Fri Jun 23 19:25:08 2017 Martin Alais
*/

#include "zappy.h"
#include "Graphic.h"

void commande_msz(t_graphic *player, t_Server *server, char *data)
{
	char data_send[100];

	(void) data;
	memset(data_send, '\0', 100);
	sprintf(data_send, "msz %d %d\n",
	server->world->width, server->world->height);
	send_message(player->fd, data_send);
}

void commande_sgt(t_graphic *player, t_Server *server, char *data)
{
	char data_send[100];

	(void) data;
	memset(data_send, '\0', 100);
	sprintf(data_send, "sgt %d\n", server->f);
	send_message(player->fd, data_send);
}

void send_message_death(int id, int fd)
{
    char buffer[512];

  sprintf(buffer, "pdi %d\n", id);
  send_message(fd, buffer);
}
