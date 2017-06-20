/*
** commande2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:08:42 2017 Martin Alais
** Last update Tue Jun 20 17:44:47 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

void commande_forward(int id, t_Server *server, char *data)
{
	t_Player *tmp;

	(void) data;
	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	start_action(server, tmp, 7);
	if (tmp->gaze == UP)
		go_up(server, id);
	else if (tmp->gaze == DOWN)
		go_down(server, id);
	else if (tmp->gaze == RIGHT)
		go_right(server, id);
	else
		go_left(server, id);
}

void commande_right(int id, t_Server *server, char *data)
{
	t_Player *tmp;

	(void) data;
	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	start_action(server, tmp, 7);
	if (tmp->gaze == UP)
		tmp->gaze = RIGHT;
	else if (tmp->gaze == RIGHT)
		tmp->gaze = DOWN;
	else if (tmp->gaze == DOWN)
		tmp->gaze = LEFT;
	else
		tmp->gaze = UP;
	send_message(tmp->fd, "OK\n");
}

void commande_left(int id, t_Server *server, char *data)
{
	t_Player *tmp;

	(void) data;
	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	start_action(server, tmp, 7);
	if (tmp->gaze == UP)
		tmp->gaze = LEFT;
	else if (tmp->gaze == LEFT)
		tmp->gaze = DOWN;
	else if (tmp->gaze == DOWN)
		tmp->gaze = RIGHT;
	else
		tmp->gaze = UP;
	send_message(tmp->fd, "OK\n");
}

void commande_incantation(int id, t_Server *server, char data)
{
	void	*mfunction_ptr[] = {incan_1, incan_2,
		incan_3, incan_4, incan_5, NULL};
	t_Player *tmp;
	void	(*fct_ptr)(int, t_Server *);

	(void) data;
	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	start_action(server, tmp, 300);
	tmp->action->is_leveling = true;
	fct_ptr = mfunction_ptr[tmp->level - 1];
	fct_ptr(id, server);
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
	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
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
	return (0);
}
