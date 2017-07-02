/*
** right_left.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:02:38 2017 Martin Alais
** Last update Sun Jul  2 14:21:32 2017 Martin Alais
*/

#include "zappy.h"
#include "Event.h"

void commande_right(int id, t_Server *server, char *data)
{
	t_Player *tmp;

	tmp = get_Player(id, server->list_player);
	if (check_valide_commande(tmp, 5, data))
		return ;
	start_action(server, tmp, 7);
	if (tmp->gaze == UP)
		tmp->gaze = RIGHT;
	else if (tmp->gaze == RIGHT)
		tmp->gaze = DOWN;
	else if (tmp->gaze == DOWN)
		tmp->gaze = LEFT;
	else
		tmp->gaze = UP;
	stok_answer(tmp, "ok\n");
	event_ppo(server, tmp);
}

void commande_left(int id, t_Server *server, char *data)
{
	t_Player *tmp;

 	tmp = get_Player(id, server->list_player);
	if (check_valide_commande(tmp, 4, data))
		return ;
	start_action(server, tmp, 7);
	if (tmp->gaze == UP)
		tmp->gaze = LEFT;
	else if (tmp->gaze == LEFT)
		tmp->gaze = DOWN;
	else if (tmp->gaze == DOWN)
		tmp->gaze = RIGHT;
	else
		tmp->gaze = UP;
	stok_answer(tmp, "ok\n");
	event_ppo(server, tmp);
}
