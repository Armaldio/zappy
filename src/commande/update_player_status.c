/*
** update_status.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 12:12:33 2017 Martin Alais
** Last update Thu Jun 29 14:58:37 2017 hamza hammouche
*/

#include "zappy.h"
#include "Event.h"

void spawn_food(t_Server *server)
{
	int x;
	int y;

	x = 0;
	while (x < server->world->width)
	{
		y = 0;
		while (y < server->world->height)
		{
			server->world->map[x][y]->food = rand() % 3;
	  	send_message_bct_pos(server, server->list_graphic, x, y);
			y += 1;
		}
		x += 1;
	}
}

void check_data_undefine(int id, char *data_recv,
	int a, t_Server *server)
{
	t_undefined *tmp;

	tmp = server->list_undefined;
	while (tmp && tmp->id != id)
		tmp = tmp->next;
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

t_Player *get_last_player(t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void undefined_to_player(t_Server *server, t_undefined *undefine, t_team *team)
{

	t_Player *tmp;
	my_add_player(server, undefine->fd);
	tmp = get_last_player(server);
	printf("Undefine %d become Player %d !\n", undefine->id, tmp->id);
	spawn_food(server);
	get_player_team(tmp, team->name, server);
	delete_undefine(server, undefine->id);
	event_new_player(server, tmp);
}
