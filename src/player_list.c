/*
** test.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Tue Jun 20 16:02:11 2017 Martin Alais
** Last update Tue Jun 20 17:24:44 2017 Martin Alais
*/

#include "zappy.h"

void my_init_player(t_Player *new, int fd, int id, t_Server *server)
{
	t_Position spaw_pos;

	new->fd = fd;
	new->id = id;
	new->is_connected = true;
	new->gaze = UP;
	spaw_pos = get_spaw_pos(server);
	if (spaw_pos.x == -1 || spaw_pos.y == -1)
		send_message(fd, "KO\n");
	new->pos.x = spaw_pos.x;
	new->pos.y = spaw_pos.y;
	set_occupation(server->world, new->pos.x, new->pos.y, true);
	new->level = 1;
	init_inventaire(new);
	init_action(new);
	ini_waiting_line(new);
	new->life_time = 0;
  	new->waitingTeam = true;
	new->death_time = 1260 / server->f;
	new->next = NULL;
	printf("New player connected with fd: %d and id: %d\n", new->fd, new->id);
}

void my_add_player(t_Server *server, int fd)
{
	t_Player *tmp;
	t_Player *new;

	new = my_malloc(sizeof(t_Player));
	tmp = server->list_player;
	if (server->list_player != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
	if (server->list_player == NULL)
		my_init_player(new, fd, 1, server);
	else
		my_init_player(new, fd, tmp->id + 1, server);
	if (server->list_player == NULL)
		server->list_player = new;
	else
		tmp->next = new;
}

void my_delete_player(t_Server *server, int id)
{
	t_Player *tmp;
	t_Player *last;

	tmp = server->list_player;
	if (tmp->id == id)
		{
			printf("Player with id %d deleted\n", server->list_player->id);
			server->list_player = tmp->next;
			free(tmp);
			return;
		}
	last = tmp;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (tmp->id == id)
		{
			printf("Player with id %d deleted\n", tmp->id);
			last->next = tmp->next;
			free(tmp);
			return;
		}
		last = tmp;
		tmp = tmp->next;
	}
}
