/*
** parser_commande.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 13:44:21 2017 Martin Alais
** Last update Fri Jun 23 15:45:41 2017 hamza hammouche
*/

#include "Graphic.h"
#include "Team.h"

void command_not_found(int id, t_Server *server)
{
  t_Player *tmp;

  tmp = get_Player(id, server->list_player);
  tmp->isGraphic == true ? send_message(tmp->fd, "suc\n") :
      send_message(tmp->fd, "ko\n");
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
	command_not_found(id, server);
	return (0);
}

bool	check_client_graphic(int id, t_Server *serv, char *data)
{
  t_Player	*player;

  player = get_Player(id, serv->list_player);
  if (strncmp(data, "Exit", 4) == 0 || (player->waitingTeam == false &&
	      player->isGraphic == false))
    return (false);
  else if (player->isGraphic == true)
    {
      if (graphic_parser(id, serv, data) == false)
				command_not_found(id, serv);
      return (true);
    }
  if (strncmp(data, "GRAPHIC", 7) == 0)
    commande_graphic(player, serv, data);
  else
    get_player_team(player, data, serv);
  return (true);
}

int parser_commande(int id, t_Server *serv, char *data)
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
  if (check_client_graphic(id, serv, data) == true)
    return (0);
  while (mcommand[a])
    {
		if (strncmp(mcommand[a], data, get_size_commmande(data)) == 0)
		{
			fct_ptr = mfunction_ptr[a];
			fct_ptr(id, serv, data);
			return (0);
		}
		a += 1;
    }
	parser_commande2(id, serv, data);
  return (0);
}
