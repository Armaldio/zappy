/*
** player_life.c for life in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Tue Jun 20 15:18:06 2017 Martin Alais
** Last update Tue Jun 20 17:22:39 2017 Martin Alais
*/

#include "zappy.h"

void update_player_life(t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;

	while (tmp)
	{
		tmp->life_time += 1;
		tmp = tmp->next;
	}
}

void check_player_death(t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;

	while (tmp)
	{
		if (tmp->life_time > tmp->death_time)
		{
			printf("Player %d is dead!\n", tmp->id);
			close(tmp->fd);
			my_delete_player(server, tmp->id);
		}
		tmp = tmp->next;
	}
}
