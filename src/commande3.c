/*
** commande3.c for  in /home/goinau_q/rendu/c/zappy/src/
**
** Made by Quentin Goinaud
** Login   <quentin.goinaud@epitech.eu>
**
** Started on  Wed Jun 21 13:56:20 2017 Quentin Goinaud
** Last update Sat Jun 24 15:13:17 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

void command_fork(int id, t_Server *server, char *data)
{
	t_Player	*egg;
	t_Player *player;
	int eggs_id;

	(void) id;
	(void) data;
	player = get_Player(id, server->list_player);
	eggs_id = my_add_eggs(server, player);
	egg = get_eggs(eggs_id, server->list_player);
	start_action(server, player, 42);
	start_action(server, egg, 42);
	add_data_in_line(egg, "Hatch");
	stok_answer(player, "ok\n");
}

void command_hatch(int id, t_Server *server, char *data)
{
	t_Player	*tmp;

	(void) data;
	tmp = get_eggs(id, server->list_player);
	if (tmp == NULL)
	{
		tmp = get_Player(id, server->list_player);
		printf("IS NOT AN EGGS\n");
	}
	else
		printf("IS AN EGGS\n");
	start_action(server, tmp, 600);
	add_data_in_line(tmp, "Bloom");
	if (tmp->controlled == true)
    	stok_answer(tmp, "ok\n");
}

void command_bloom(int id, t_Server *server, char *data)
{
	t_Player	*tmp;

	(void) data;
	tmp = get_eggs(id, server->list_player);
	if (tmp == NULL)
		tmp = get_Player(id, server->list_player);
	if (tmp->isEgg == false)
		return;
	tmp->gaze = rand() % 4;
	tmp->isEgg = false;
	tmp->is_connected = false;
}

int command_set(int id, t_Server *server, char *data)
{
	t_Player *tmp;
	char *all_stone[] = {"linemate", "deraumere", "sibur",
	"mendiane", "phiras", "thystane", "food", NULL};
	void	*mfunction_ptr[] = {set_linemate, set_deraumere,
	set_sibur, set_mendiane, set_phiras, set_thystane, NULL};
	void	(*fct_ptr)(int id, t_Server *);
	int a;

	a = 0;
	data += 4;
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

void command_inventory(int id, t_Server *server, char *data)
{
	char send_data[4096];
	t_Player *tmp;

	(void) data;
	tmp = get_Player(id, server->list_player);
	start_action(server, tmp, 1);
	memset(send_data, '\0', 4096);
	sprintf(send_data, "[food %d, linemate %d, deraumere %d, sibur %d, \
mendiane %d, phiras %d, thystane %d]\n", tmp->inventaire->food,
	tmp->inventaire->linemate, tmp->inventaire->deraumere,
	tmp->inventaire->sibur, tmp->inventaire->mendiane,
	tmp->inventaire->phiras, tmp->inventaire->thystane);
	stok_answer(tmp, send_data);
}
