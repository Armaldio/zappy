/*
** parser_commande.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 13:44:21 2017 Martin Alais
** Last update Thu Jun 22 15:50:07 2017 Martin Alais
*/

#include "zappy.h"
#include "Team.h"

void command_not_found(int id, t_Server *server)
{
  t_Player *tmp;

  tmp = server->list_player;
  while (tmp->next && tmp->id != id)
    tmp = tmp->next;
  send_message(tmp->fd, "KO\n");
}

int get_size_commmande(char *str)
{
	int a;

	a = 0;
	while (str[a] != '\0' && str[a] != ' ' && str[a] != '\n')
		a += 1;
	return (a);
}

int parser_commande2(int id, t_Server *server, char *data)
{
	char	*mcommand[] = {"Eject", "POS", "Broadcast", "Inventory", NULL};
	void	*mfunction_ptr[] = {command_eject, command_pos,
  command_broadcast, command_inventory, NULL};
	void	(*fct_ptr)(int, t_Server *, char *);
	int		a;

	a = 0;
	while (mcommand[a])
	{
		if (strncmp(mcommand[a], data, get_size_commmande(data)) == 0)
		{
			fct_ptr = mfunction_ptr[a];
			fct_ptr(id, server, data);
			return (0);
		}
		a += 1;
	}
	if (graphic_parser(id, server, data) == false)
		command_not_found(id, server);
	return (0);
}

int parser_commande(int id, t_Server *server, char *data)
{
    char	*mcommand[] = {"Forward", "Right", "Left", "Incantation",
  "Take", "Look", "Exit", "Fork", "Hatch", "Bloom", "Set", NULL};
    void	*mfunction_ptr[] = {commande_forward, commande_right,
      commande_left, commande_incantation, command_take, command_look,
  exit_client, command_fork, command_hatch, command_bloom, command_set, NULL};
  void		(*fct_ptr)(int, t_Server *, char *);
  int		a;

  if (data == NULL)
    return (0);
  a = 0;
  if (get_player_team(get_Player(id, server->list_player), data, server))
    return (0);
  while (mcommand[a])
    {
		if (strncmp(mcommand[a], data, get_size_commmande(data)) == 0)
		{
			fct_ptr = mfunction_ptr[a];
			fct_ptr(id, server, data);
			return (0);
		}
		a += 1;
    }
	parser_commande2(id, server, data);
  return (0);
}
