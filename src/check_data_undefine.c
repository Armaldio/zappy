/*
** check_data_undefine.c for zappy in /home/hammouche/Documents/PSU_2016/zappy/src/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Sat Jun 24 12:50:08 2017 hamza hammouche
** Last update Sat Jun 24 12:51:34 2017 hamza hammouche
*/

#include <time.h>
#include "zappy.h"
#include "Server.h"

void print_player(t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next != NULL)
	{
		printf("Player id: %d\n", tmp->id);
		printf("pos_x: %d\n", tmp->pos.x);
		printf("pos_y: %d\n\n", tmp->pos.y);
		tmp = tmp->next;
	}
	printf("Player id: %d\n", tmp->id);
	printf("pos_x: %d\n", tmp->pos.x);
	printf("pos_y: %d\n\n", tmp->pos.y);
}

bool check_valide_team(char *team_name, t_Server *server,
		       t_undefined *undefine)
{
	t_team *tmp;

	tmp = server->list_teams;
	while (tmp)
	{
		if (strncmp(tmp->name, team_name, strlen(tmp->name)) == 0)
		{
			undefined_to_player(server, undefine, tmp);
			return (true);
		}
		tmp = tmp->next;
	}
	return (false);
}

void check_data_undefine(t_undefined *tmp, char *data_recv,
			 int a, t_Server *server)
{
	if (a == 0)
	{
		printf("Undefined with id %d disconected\n", tmp->id);
		delete_undefine(server, tmp->id);
	}
	else
	{
		if (strcmp(data_recv, "GRAPHIC\n") == 0)
			undefined_to_graphic(server, tmp);
		else if (check_valide_team(data_recv, server, tmp) != true)
			send_message(tmp->fd, "ko\n");
	}
}
