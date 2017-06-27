/*
** fork.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:33:40 2017 Martin Alais
** Last update Mon Jun 26 13:34:28 2017 Martin Alais
*/

#include "zappy.h"
#include "Event.h"

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
	event_pfk(server, player);
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
		tmp = get_Player(id, server->list_player);
	start_action(server, tmp, 600);
	event_enw(server, tmp->father_id, tmp);
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
	event_eht(server, tmp);
}
