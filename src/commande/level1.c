/*
** level1.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:12:47 2017 Martin Alais
** Last update Wed Jun 28 15:30:00 2017 Martin Alais
*/

#include "zappy.h"

int check_nbr_at_level(t_Server *server, t_Player *player, int level)
{
	t_Player *tmp;
	int nbr;

	nbr = 0;
	tmp = server->list_player;
	while (tmp)
	{
		if (tmp->pos.x == player->pos.x &&  tmp->pos.y == player->pos.y &&
			tmp->level == level)
			nbr += 1;
		tmp = tmp->next;
	}
	return (nbr);
}

int *build_tab_1()
{
	int *tab;
	tab = malloc(sizeof(int) * 7);
	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	tab[5] = 0;
	tab[6] = 0;
	return (tab);
}

void incan_1(t_Server *server, t_Player *player)
{
	if (compare_tab(build_tab_1(), build_tab(server, player)) == true &&
		nbr_case(server, player) == 1)
		{
			send_message(player->fd, "ok\n");
		}
	else
		send_message(player->fd, "ko\n");
	player->action->is_leveling = false;
}

void end_level1(t_Server *server, t_Player *player)
{
	if (compare_tab(build_tab_1(), build_tab(server, player)) == true &&
		nbr_case(server, player) == 1)
		{
			server->world->map[player->pos.x][player->pos.y]->linemate = 0;
			player->level = 2;
			printf("Player %d reach level 2!\n", player->id);
	    	event_endI(server, player);
			stok_answer(player, "ok\n");
		}
		else
		{
			event_endI(server, player);
			stok_answer(player, "ko\n");
		}
		player->action->is_leveling = false;
		player->action->try_level_up = false;
}
