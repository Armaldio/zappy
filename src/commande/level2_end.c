/*
** level2_end.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Wed Jun 28 16:36:53 2017 Martin Alais
** Last update Thu Jun 29 15:33:34 2017 Martin Alais
*/

#include "zappy.h"

int *build_tab_2()
{
	int *tab;
	tab = malloc(sizeof(int) * 7);
	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 1;
	tab[3] = 1;
	tab[4] = 0;
	tab[5] = 0;
	tab[6] = 0;
	return (tab);
}

bool	is_ready_to_up_2(t_Player *tmp, t_Player *player)
{
	if (tmp->id != player->id && tmp->level == 2)
		return (true);
	return (false);
}

void clean_player2(t_Player *player)
{
	player->action->is_leveling = false;
	send_message(player->fd, "ko\n");
}

bool incan_2bis(t_Server *server, t_Player *player)
{
	t_Player *tmp;

	tmp = server->list_player;
	if (nbr_case_rdy(server, player) == 2)
	{
		while (tmp && is_ready_to_up_2(tmp, player) == false)
			tmp = tmp->next;
		if (is_ready_to_up_2(tmp, player) == true)
		{
			player->action->is_leveling = false;
			tmp->action->is_leveling = false;
			player->action->friend_list[0] = tmp->id;
			tmp->action->friend_list[0] = player->id;
			send_message(player->fd, "ko\n");
			send_message(tmp->fd, "Elevation Underway\n");
			return (false);
		}
		else
		{
			clean_player2(player);
			return (false);
		}
	}
	return (true);
}

void incan_2(t_Server *server, t_Player *player)
{
	t_Player *tmp;

	tmp = server->list_player;
	if (compare_tab(build_tab_2(), build_tab(server, player)) &&
		nbr_case_rdy(server, player) == 2)
	{
		while (tmp && is_ready_to_up_2(tmp, player) == false)
			tmp = tmp->next;
		if (is_ready_to_up_2(tmp, player) == true)
		{
			set_incan2(player, tmp);
			player->action->friend_list[0] = tmp->id;
			tmp->action->friend_list[0] = player->id;
			send_message(player->fd, "Elevation Underway\n");
			send_message(tmp->fd, "Elevation Underway\n");
			return ;
		}
		else
			return (clean_player2(player));
	}
	else if (incan_2bis(server, player) == false)
		return;
	player->action->is_leveling = false;
	send_message(player->fd, "ko\n");
}
