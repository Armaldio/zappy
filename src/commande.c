#include "zappy.h"

void commande_forward(int id, t_Server *server, char *data)
{
	t_Player *tmp;

	(void) data;
	tmp = server->list_player;
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
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
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->gaze == UP)
		tmp->gaze = RIGHT;
	else if (tmp->gaze == RIGHT)
		tmp->gaze = DOWN;
	else if (tmp->gaze == DOWN)
		tmp->gaze = LEFT;
	else
		tmp->gaze = UP;
}

void commande_left(int id, t_Server *server, char *data)
{
	t_Player *tmp;

	(void) data;
	tmp = server->list_player;
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->gaze == UP)
		tmp->gaze = LEFT;
	else if (tmp->gaze == LEFT)
		tmp->gaze = DOWN;
	else if (tmp->gaze == DOWN)
		tmp->gaze = RIGHT;
	else
		tmp->gaze = UP;
}

void parser_commande(int id, t_Server *server, char *data)
{
	char	*mcommand[] = {"Forward", "Right", "Left", NULL};
	void	*mfunction_ptr[] = {commande_forward, commande_right, commande_left, NULL};
	void	(*fct_ptr)(int, t_Server *, char *);
	int		a;

	a = 0;
	while(mcommand[a])
	{
		if (strncmp(mcommand[a], data, strlen(mcommand[a])) == 0)
		{
			fct_ptr = mfunction_ptr[a];
			fct_ptr(id, server, data);
		}
		a += 1;
	}
}
