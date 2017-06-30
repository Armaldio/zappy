/*
** tna.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/graphic/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 16:38:29 2017 Martin Alais
** Last update Fri Jun 30 16:32:52 2017 Martin Alais
*/
#include "zappy.h"
#include "Graphic.h"

void commande_tna(t_graphic *player, t_Server *server, char *data)
{
	t_team *tmp;
	char data_send[100];

  (void) data;
	tmp = server->list_teams;
	while (tmp)
	{
		memset(data_send, '\0', 100);
		sprintf(data_send, "tna %s\n", tmp->name);
		send_message_graphic(player, data_send);
		tmp = tmp->next;
	}
}
