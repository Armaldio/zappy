/*
** parser_commande.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 13:44:21 2017 Martin Alais
** Last update Sun Jul  2 16:29:11 2017 hamza hammouche
*/

#include "Graphic.h"
#include "Team.h"

void 	command_connect_nbr(int id, t_Server *serv, char *param)
{
  t_Player *player;
  t_team		*team;
  char			buff[128];

  (void)param;
  player = get_Player(id, serv->list_player);
  if ((team = get_team(serv->list_teams, NULL, player->teamId)) == NULL)
      return;
  sprintf(buff, "%d\n", serv->nbClientMax - team->nbMember);
  send_message(player, buff);
}

void command_not_found(int id, t_Server *server)
{
  t_Player *tmp;

  tmp = get_Player(id, server->list_player);
  send_message(tmp, "ko\n");
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
  char	*mcommand[] = {"Eject", "Broadcast", "Inventory",
  "Connect_nbr", NULL};
  void	*mfunction_ptr[] = {command_eject,
  command_broadcast, command_inventory, command_connect_nbr, NULL};
  void	(*fct_ptr)(int, t_Server *, char *);
  int		a;

  a = 0;
  while (mcommand[a])
    {
      printf("%s\n", mcommand[a]);
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
  add_rand_food(serv);
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
