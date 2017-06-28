/*
** level5.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:28:30 2017 Martin Alais
** Last update Wed Jun 28 14:28:29 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

int *build_tab_5()
{
	int *tab;
	tab = malloc(sizeof(int) * 7);
	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 2;
	tab[3] = 1;
	tab[4] = 3;
	tab[5] = 0;
	tab[6] = 0;
	return (tab);
}

t_Player **get_list_level_5(t_Server *server, t_Player *player)
{
	t_Player **tmp2;
	t_Player *tmp;
	int a;

	a = 0;
	tmp2 = my_malloc(sizeof(t_Player *) * 3);
	tmp2[0] = NULL;
	tmp2[1] = NULL;
	tmp2[2] = NULL;
	tmp = server->list_player;
	while (tmp)
	{
		if (tmp->id != player->id && tmp->level == 5 && a < 3)
		{
			tmp2[a] = tmp;
			a += 1;
		}
		tmp = tmp->next;
	}
	return (tmp2);
}

void complete_struct5(t_Player **tmp2, t_Player *player)
{
	player->action->friend_list[0] = tmp2[0]->id;
	player->action->friend_list[1] = tmp2[1]->id;
	player->action->friend_list[2] = tmp2[2]->id;
	tmp2[0]->action->friend_list[0] = player->id;
	tmp2[0]->action->friend_list[1] = tmp2[1]->id;
	tmp2[0]->action->friend_list[2] = tmp2[2]->id;
	tmp2[1]->action->friend_list[0] = player->id;
	tmp2[1]->action->friend_list[1] = tmp2[0]->id;
	tmp2[1]->action->friend_list[2] = tmp2[2]->id;
	tmp2[2]->action->friend_list[0] = player->id;
	tmp2[2]->action->friend_list[1] = tmp2[0]->id;
	tmp2[2]->action->friend_list[2] = tmp2[1]->id;
}

void incan_5(t_Server *server, t_Player *player)
{
	t_Player **tmp2;

	if (compare_tab(build_tab_5(), build_tab(server, player)) &&
	nbr_case_rdy(server, player) == 4)
	if (check_nbr_at_level(server, player, 5) >= 4)
	{
		tmp2 = get_list_level_5(server, player);
		if (tmp2[0] != NULL && tmp2[1] != NULL && tmp2[2] != NULL)
		{
			player->action->is_leveling = false;
			tmp2[0]->action->is_leveling = false;
			tmp2[1]->action->is_leveling = false;
			tmp2[2]->action->is_leveling = false;
			complete_struct5(tmp2, player);
			free (tmp2);
		}
	}
}
