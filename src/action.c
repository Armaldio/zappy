/*
** action.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Tue Jun 20 10:57:46 2017 Martin Alais
** Last update Thu Jun 22 18:28:51 2017 hamza hammouche
*/

#include <time.h>
#include "zappy.h"

void send_message_pie(t_Player *p, int r)
{
	char buffer[512];

  sprintf(buffer, "pie %d %d %d\n", p->pos.x, p->pos.y, r);
  send_message(p->fd, buffer);
}

void init_action(t_Player *player)
{
	player->action = my_malloc(sizeof(t_action));
	player->action->end_time = 0;
	player->action->is_leveling = false;
	player->action->is_working = false;
	player->action->start_time = 0;
}

void start_action(t_Server *server, t_Player *player, int action_time)
{
	time_t	now;
	struct tm	*tm;

	now = time(0);
	if ((tm = localtime (&now)) == NULL)
		printf ("Error extracting time, no changes\n");
	player->action->start_time = tm->tm_sec;
	player->action->end_time = player->action->start_time
	+ (action_time / server->f);
	player->action->is_working = true;
	player->action->is_leveling = false;
	printf("Player %d starting an action for %dt\n", player->id, action_time);
}

void check_action_status(t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp)
	{
		if (tmp->action->start_time > tmp->action->end_time)
		{
			tmp->action->end_time = 0;
			tmp->action->start_time = 0;
			tmp->action->is_working = false;
			if (tmp->action->is_leveling == true)
	    {
				server->isGraphic == true ? send_message_pie(tmp, 0) :
		  send_message(tmp->fd, "ko\n");
	    }
			tmp->action->is_leveling = false;
			printf("Player %d terminated an action\n", tmp->id);
		}
		tmp = tmp->next;
	}
}

void action_update_time(t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp)
	{
		if (tmp->action->is_working == true)
			tmp->action->start_time += 1;
		tmp = tmp->next;
	}
}
