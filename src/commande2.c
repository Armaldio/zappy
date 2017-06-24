/*
** commande2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:08:42 2017 Martin Alais
** Last update Sat Jun 24 12:02:52 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"
#include <string.h>

void commande_forward(int id, t_Server *server, char *data)
{
	t_Player *tmp;

	(void) data;
  tmp = get_Player(id, server->list_player);
	start_action(server, tmp, 7);
	if (tmp->gaze == UP)
		go_up(server, id, true);
	else if (tmp->gaze == DOWN)
		go_down(server, id, true);
	else if (tmp->gaze == RIGHT)
		go_right(server, id, true);
	else
		go_left(server, id, true);
	tmp = server->list_player;
	while (tmp)
	{
		if (tmp->isEgg == true)
			printf("Eggs %d\n", tmp->id);
		tmp = tmp->next;
	}
}

void commande_right(int id, t_Server *server, char *data)
{
	t_Player *tmp;

	(void) data;
  tmp = get_Player(id, server->list_player);
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
}

void commande_left(int id, t_Server *server, char *data)
{
	t_Player *tmp;

	(void) data;
  tmp = get_Player(id, server->list_player);
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
}

void commande_incantation(int id, t_Server *server, char data)
{
	t_Player *tmp;
  t_Player	*ptmp;
  char			buffer[2048];
  char			nb[15];

	(void) data;
  ptmp = server->list_player;
  tmp = get_Player(id, server->list_player);
	start_action(server, tmp, 300);
	tmp->action->is_leveling = true;
  sprintf(buffer, "pic %d %d %d %d", tmp->pos.x, tmp->pos.y, tmp->level,
	  tmp->id);
  while (ptmp)
    {
      if (ptmp != tmp)
			{
	  		sprintf(nb, " %d", ptmp->id);
	  		strcat(buffer, nb);
			}
      ptmp = ptmp->next;
    }
  strcat(buffer, "\n");
  send_message_position(server->list_player, tmp->pos.x, tmp->pos.y, buffer);
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
	tmp->isGraphic == true ? stok_answer(tmp, "sbp\n") :
      stok_answer(tmp, "ko\n");
	return (0);
}
