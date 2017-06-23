/*
** sst_update_time.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/graphic/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Fri Jun 23 10:39:15 2017 Martin Alais
** Last update Fri Jun 23 11:46:53 2017 Martin Alais
*/

#include "zappy.h"
#include "Graphic.h"

void update_action_time(t_Player *player, int new_time, t_Server *server)
{
	printf("Old start time: %d\n", player->action->start_time);
	printf("Old end time: %d\n", player->action->end_time);
	player->action->start_time = (player->action->start_time * server->f) / new_time;
	player->action->end_time = (player->action->end_time * server->f) / new_time;
	printf("New start time: %d\n", player->action->start_time);
	printf("New end time: %d\n", player->action->end_time);
}

void update_player_life_time(t_Player *player, int new_time, t_Server *server)
{
	player->death_time = (126 / new_time); // faux
	player->life_time = (player->life_time * server->f) / new_time;
}

void commande_sst(t_Player *player, t_Server *server, char *data2)
{
	int new_time;
	t_Player *tmp;

	data2 += 4;
	tmp = server->list_player;
	new_time = atoi(data2);
	if (new_time <= 1)
	{
		send_message(player->fd, "sbp\n");
		return ;
	}
	while (tmp)
	{
		if (tmp->action->is_working == true)
			update_action_time(tmp, new_time, server);
		update_player_life_time(tmp, new_time, server);
		tmp = tmp->next;
	}
	server->f = new_time;
	commande_sgt(player, server, data2);
	printf("server time update to %d\n", server->f);
}
