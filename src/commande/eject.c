/*
** eject.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 12:07:44 2017 Martin Alais
** Last update Fri Jun 30 16:18:33 2017 Martin Alais
*/

#include "zappy.h"
#include "Event.h"

void eject_player(t_Server *server, t_Player *player)
{
	if (player->gaze == UP)
	{
		go_up(server, player->id, false);
		send_message(player, "eject: 1\n");
	}
	else if (player->gaze == DOWN)
	{
		go_down(server, player->id, false);
		send_message(player, "eject: 3\n");
	}
	else if (player->gaze == RIGHT)
	{
		go_right(server, player->id, false);
		send_message(player, "eject: 2\n");
	}
	else
	{
		go_left(server, player->id, false);
		send_message(player, "eject: 4\n");
	}
}

void command_eject(int id, t_Server *server, char *data)
{
	t_Player *tmp;
	t_Player *player;
	char buffer[512];

	(void) data;
	player = get_Player(id, server->list_player);
	tmp = server->list_player;
	start_action(server, player, 7);
	event_eject(server, tmp);
	while (tmp)
	{
		if (tmp->id != player->id && tmp->pos.x == player->pos.x
		    && tmp->pos.y == player->pos.y)
		{
			printf("Player %d ejected by player %d !\n", tmp->id, player->id);
			eject_player(server, tmp);
			event_eject(server, tmp);
		}
		tmp = tmp->next;
	}
	sprintf(buffer, "pex %d\n", id);
	stok_answer(tmp, "ok\n");
}
