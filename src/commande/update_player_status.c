/*
** update_status.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 12:12:33 2017 Martin Alais
** Last update Sat Jul  1 14:27:44 2017 Martin Alais
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

void complete_read_undefine(t_undefined *player, char *data_recv,
	t_Server *server)
{
	int a;

	a = zappy_getline(player->read_buffer, data_recv);
	strcat(data_recv, "\n");
	printf("%d: %s", player->id, data_recv);
	check_data_undefine(player->id, data_recv, server);

	memset(data_recv, '\0', 4095);
	while (a > 0)
	{
		a = zappy_getline(player->read_buffer, data_recv);
		if (a != 0)
		{
			strcat(data_recv, "\n");
			printf("%d: %s", player->id, data_recv);
			check_data_undefine(player->id, data_recv, server);
			memset(data_recv, '\0', 4095);
		}
	}
}

void check_data_undefine(int id, char *data_recv, t_Server *server)
{
	t_undefined *tmp;

	tmp = server->list_undefined;
	while (tmp && tmp->id != id)
		tmp = tmp->next;
	if (tmp == NULL || tmp->id != id)
		return ;
	if (strcmp(data_recv, "GRAPHIC\n") == 0)
		undefined_to_graphic(server, tmp);
	else if (check_valide_team(data_recv, server, tmp) != true)
		send_message_undefine(tmp, "ko\n");
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
