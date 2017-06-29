/*
** action.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Tue Jun 20 10:57:46 2017 Martin Alais
** Last update Thu Jun 29 14:24:23 2017 Martin Alais
*/

#include <time.h>
#include "zappy.h"

void send_message_pie(t_graphic *head, t_Player *p)
{
	char buffer[512];
  t_graphic	*tmp;

  sprintf(buffer, "pie %d %d %d\n", p->pos.x, p->pos.y, 1);
  tmp = head;
  while (tmp)
    {
      send_message(tmp->fd, buffer);
      tmp = tmp->next;
    }
}

void init_action(t_Player *player)
{
	player->action = my_malloc(sizeof(t_action));
	player->action->end_time = 0;
	player->action->is_leveling = false;
	player->action->is_working = false;
	player->action->try_level_up = false;
	player->action->start_time = 0;
	player->action->friend_list = my_malloc(sizeof(int) * 7);
	player->action->friend_list[0] = 0;
	player->action->friend_list[1] = 0;
	player->action->friend_list[2] = 0;
	player->action->friend_list[3] = 0;
	player->action->friend_list[4] = 0;
	player->action->friend_list[5] = 0;
	player->action->friend_list[6] = 0;
}

void start_action(t_Server *server, t_Player *player, int action_time)
{
	time_t	now;
	struct tm	*tm;

	now = time(0);
	if ((tm = localtime (&now)) == NULL)
		printf ("Error extracting time, no changes\n");
	player->action->start_time = server->tmp_time;
	player->action->end_time = player->action->start_time
	+ (action_time / server->f);
	player->action->is_working = true;
	player->action->is_leveling = false;
	if (player->isEgg == false)
		printf("Player %d starting an action for %dt\n",
		player->id, action_time);
	else
		printf("Eggs %d starting an action for %dt\n",
		player->id, action_time);
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
			if (tmp->action->try_level_up == true)
	    		send_to_level_up(tmp, server);
			send_answer(tmp);
			if (tmp->isEgg == false)
				printf("Player %d terminated an action\n", tmp->id);
			else
				printf("Eggs %d terminated an action\n", tmp->id);
		}
		tmp = tmp->next;
	}
}

void action_update_time(t_Server *server, double elapsed_time)
{
	t_Player *tmp;

	tmp = server->list_player;
	if (elapsed_time < 0)
		return;
	while (tmp)
	{
		if (tmp->action->is_working == true)
		{
			tmp->action->start_time += elapsed_time;
		}
		tmp = tmp->next;
	}
}
