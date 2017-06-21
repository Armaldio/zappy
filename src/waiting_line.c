/*
** waiting_line.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Tue Jun 20 12:00:37 2017 Martin Alais
** Last update Wed Jun 21 16:19:06 2017 Martin Alais
*/

#include <string.h>
#include "zappy.h"

void ini_waiting_line(t_Player *player)
{
	player->waiting_line = my_malloc(sizeof(t_waiting_line));
	player->waiting_line->line = my_malloc(sizeof(char *) * 10);
	player->waiting_line->line[0] = NULL;
	player->waiting_line->nbr_ordre = 0;
}

void remove_newline(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		if (str[a] == '\n')
			str[a] = '\0';
		a += 1;
	}
}

int add_data_in_line(t_Player * player, char *order)
{
	if (player->waiting_line->nbr_ordre > 9)
	{
		printf("Too much data in queue\n");
		return (0);
	}
	remove_newline(order);
	player->waiting_line->line[player->waiting_line->nbr_ordre] =
	my_malloc(sizeof(char) * (strlen(order) + 1) );
	memset(player->waiting_line->line[player->waiting_line->nbr_ordre],
		'\0', (strlen(order)));
	memcpy(player->waiting_line->line[player->waiting_line->nbr_ordre],
		order, strlen(order) - 1);
	strcat(player->waiting_line->line[player->waiting_line->nbr_ordre], "\0");
	player->waiting_line->nbr_ordre += 1;
	player->waiting_line->line[player->waiting_line->nbr_ordre] = NULL;
	return (0);
}

void get_data_from_line2(t_Player *player, int a)
{
	player->waiting_line->line[a] = my_malloc(sizeof(char) *
	(strlen(player->waiting_line->line[a + 1]) + 1));
	memset(player->waiting_line->line[a], '\0',
	strlen(player->waiting_line->line[a + 1]) + 1);
	memcpy(player->waiting_line->line[a],
		player->waiting_line->line[a + 1],
		strlen(player->waiting_line->line[a + 1]));
}

char *get_data_from_line(t_Player *player)
{
	char *res;
	int a;

	a = 0;
	if (player->waiting_line->line[0] == NULL)
		return (NULL);
	res = my_malloc(sizeof(char) *
	(strlen(player->waiting_line->line[0]) + 1));
	memset(res, '\0', (strlen(player->waiting_line->line[0]) + 1));
	memcpy(res, player->waiting_line->line[0],
		strlen(player->waiting_line->line[0]));
	strcat(res, "\0");
	while (player->waiting_line->line[a])
	{
		free(player->waiting_line->line[a]);
		if (player->waiting_line->line[a + 1] == NULL)
		{
			player->waiting_line->line[a] = NULL;
			player->waiting_line->nbr_ordre -= 1;
			return (res);
		}
		get_data_from_line2(player, a);
		a += 1;
	}
	return (res);
}
