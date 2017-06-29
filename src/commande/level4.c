/*
** level4.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:26:53 2017 Martin Alais
** Last update Thu Jun 29 15:34:26 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

void clean_player4(t_Player *player)
{
	player->action->is_leveling = false;
	player->action->friend_list[0] = 0;
	player->action->friend_list[1] = 0;
	player->action->friend_list[2] = 0;
	player->action->friend_list[3] = 0;
	send_message(player->fd, "ko\n");
}

void complete_struct4bis(t_Player **tmp2, t_Player *player)
{
	player->action->friend_list[0] = tmp2[0]->id;
	player->action->friend_list[1] = tmp2[1]->id;
	player->action->friend_list[2] = tmp2[2]->id;
	tmp2[0]->action->friend_list[0] = player->fd;
	tmp2[0]->action->friend_list[1] = tmp2[1]->fd;
	tmp2[0]->action->friend_list[2] = tmp2[2]->fd;
	tmp2[1]->action->friend_list[0] = player->fd;
	tmp2[1]->action->friend_list[1] = tmp2[0]->fd;
	tmp2[1]->action->friend_list[2] = tmp2[2]->fd;
	tmp2[2]->action->friend_list[0] = player->fd;
	tmp2[2]->action->friend_list[1] = tmp2[0]->fd;
	tmp2[2]->action->friend_list[2] = tmp2[1]->fd;
	send_message(player->fd, "ko\n");
	send_message(tmp2[0]->fd, "Elevation Underway\n");
	send_message(tmp2[1]->fd, "Elevation Underway\n");
	send_message(tmp2[2]->fd, "Elevation Underway\n");
}

bool incan_4bis(t_Server *server, t_Player *player)
{
	t_Player **tmp2;

	if (check_nbr_at_level(server, player, 4) == 4)
	{
		tmp2 = get_list_level_4(server, player);
		player->action->is_leveling = false;
		tmp2[0]->action->is_leveling = false;
		tmp2[1]->action->is_leveling = false;
		tmp2[2]->action->is_leveling = false;
		complete_struct4bis(tmp2, player);
		free(tmp2);
		return (true);
	}
	return (true);
}

void complete_struct4(t_Player **tmp2, t_Player *player)
{
	player->action->friend_list[0] = tmp2[0]->id;
	player->action->friend_list[1] = tmp2[1]->id;
	player->action->friend_list[2] = tmp2[2]->id;
	tmp2[0]->action->friend_list[0] = player->fd;
	tmp2[0]->action->friend_list[1] = tmp2[1]->fd;
	tmp2[0]->action->friend_list[2] = tmp2[2]->fd;
	tmp2[1]->action->friend_list[0] = player->fd;
	tmp2[1]->action->friend_list[1] = tmp2[0]->fd;
	tmp2[1]->action->friend_list[2] = tmp2[2]->fd;
	tmp2[2]->action->friend_list[0] = player->fd;
	tmp2[2]->action->friend_list[1] = tmp2[0]->fd;
	tmp2[2]->action->friend_list[2] = tmp2[1]->fd;
	send_message(player->fd, "Elevation Underway\n");
	send_message(tmp2[0]->fd, "Elevation Underway\n");
	send_message(tmp2[1]->fd, "Elevation Underway\n");
	send_message(tmp2[2]->fd, "Elevation Underway\n");
}

void incan_4(t_Server *server, t_Player *player)
{
	t_Player **tmp2;

	if (compare_tab(build_tab_4(), build_tab(server, player)) &&
	check_nbr_at_level(server, player, 4) == 4)
	{
		tmp2 = get_list_level_4(server, player);
		if (tmp2[0] != NULL && tmp2[1] != NULL && tmp2[2] != NULL)
		{
			player->action->is_leveling = false;
			tmp2[0]->action->is_leveling = false;
			tmp2[1]->action->is_leveling = false;
			tmp2[2]->action->is_leveling = false;
			complete_struct4(tmp2, player);
			free(tmp2);
			return ;
		}
		else
			return (clean_player4(player));
	}
	else if (incan_4bis(server, player) == false)
		return ;
	clean_player4(player);
}
