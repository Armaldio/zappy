/*
** msz.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/graphic/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 16:01:38 2017 Martin Alais
** Last update Sat Jun 24 19:00:08 2017 hamza hammouche
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

void send_message_death(t_graphic *head, int id)
{
  char buffer[512];
  t_graphic *tmp;

  sprintf(buffer, "pdi %d\n", id);
  tmp = head;
  while (tmp)
    {
      send_message(tmp->fd, buffer);
      tmp = tmp->next;
    }
}
