/*
** take.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:03:54 2017 Martin Alais
** Last update Mon Jun 26 13:05:20 2017 Martin Alais
*/

#include "zappy.h"
#include "Event.h"

void take_thystane(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (server->world->map[tmp->pos.x][tmp->pos.y]->thystane >= 1)
	{
		server->world->map[tmp->pos.x][tmp->pos.y]->thystane -= 1;
		tmp->inventaire->thystane += 1;
		event_take(server, tmp, 6);
		stok_answer(tmp, "ok\n");
	}
	else
		stok_answer(tmp, "ko\n");
}

void take_food(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (server->world->map[tmp->pos.x][tmp->pos.y]->food >= 1)
	{
		server->world->map[tmp->pos.x][tmp->pos.y]->food -= 1;
		tmp->inventaire->food += 1;
		event_take(server, tmp, 0);
		stok_answer(tmp, "ok\n");
	}
	else
		stok_answer(tmp, "ko\n");
}

int command_take(int id, t_Server *server, char *data)
{
	t_Player *tmp;
	char *all_stone[] = {"linemate", "deraumere", "sibur",
	"mendiane", "phiras", "thystane", "food", NULL};
	void	*mfunction_ptr[] = {take_linemate, take_deraumere,
	take_sibur, take_mendiane, take_phiras, take_thystane, take_food, NULL};
	void	(*fct_ptr)(int id, t_Server *);
	int a;

	a = 0;
	data += 5;
	tmp = get_Player(id, server->list_player);
	start_action(server, tmp, 7);
	while (all_stone[a])
	{
		if (strncmp(all_stone[a], data, strlen(all_stone[a])) == 0)
		{
			fct_ptr = mfunction_ptr[a];
			fct_ptr(id, server);
			return (0);
		}
		a += 1;
	}
	stok_answer(tmp, "ko\n");
	return (0);
}
