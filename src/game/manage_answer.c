/*
** manage_answer.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Fri Jun 23 14:40:46 2017 Martin Alais
** Last update Thu Jun 29 12:57:06 2017 Martin Alais
*/

#include "zappy.h"

void stok_answer(t_Player *player, char *answer)
{
	memset(player->action->data_to_send, '\0',
	strlen(player->action->data_to_send));
	memcpy(player->action->data_to_send, answer,
		strlen(answer) > 4095 ? 4095 : strlen(answer));
}

void send_answer(t_Player *player)
{
	if (player->action->data_to_send[0] != '\0')
	{
		printf("Sending answer to %d with message: %s", player->fd,
		player->action->data_to_send);
		send_message(player->fd, player->action->data_to_send);
	}
}
