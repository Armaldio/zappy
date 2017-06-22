/*
** commande3.c for  in /home/goinau_q/rendu/c/zappy/src/
**
** Made by Quentin Goinaud
** Login   <quentin.goinaud@epitech.eu>
**
** Started on  Wed Jun 21 13:56:20 2017 Quentin Goinaud
** Last update Thu Jun 22 17:39:53 2017 hamza hammouche
*/

#include "zappy.h"
#include "Incantation.h"

void command_fork(int id, t_Server *server, char *data)
{
  t_Player	*tmp;
  char			buffer[512];

  (void) id;
  (void) data;
  my_add_player_id(server, -1);
  tmp = get_Player(id, server->list_player);
  tmp->is_connected = true;
  tmp->controlled = false;
  tmp->isEgg = true;
  tmp->pos = get_spaw_pos(server);
  start_action(server, tmp, 42);
  add_data_in_line(tmp, "Hatch");
  sprintf(buffer, "pfk %d", tmp->id);
  server->isGraphic == true ?  send_message(tmp->fd, buffer):
      send_message(tmp->fd, "ok\n");
}

void command_hatch(int id, t_Server *server, char *data)
{
  t_Player	*tmp;

  (void) data;
  tmp = get_Player(id, server->list_player);
  start_action(server, tmp, 600);
  add_data_in_line(tmp, "Bloom");
}

void command_bloom(int id, t_Server *server, char *data)
{
  t_Player	*tmp;

  (void) data;
  tmp = get_Player(id, server->list_player);
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
  server->isGraphic == true ? send_message(tmp->fd, "sbp\n") :
      send_message(tmp->fd, "ko\n");
	return (0);
}

void command_inventory(int id, t_Server *server, char *data)
{
	char send_data[4096]; // c'est propre tg
	t_Player *tmp;

	(void) data;
	tmp = get_Player(id, server->list_player);
	memset(send_data, '\0', 4096);
	sprintf(send_data, "[food %d, linemate %d, deraumere %d, sibur %d, \
mendiane %d, phiras %d, thystane %d]\n", tmp->inventaire->food,
	tmp->inventaire->linemate, tmp->inventaire->deraumere,
	tmp->inventaire->sibur, tmp->inventaire->mendiane,
	tmp->inventaire->phiras, tmp->inventaire->thystane);
	send_message(tmp->fd, send_data);
}
