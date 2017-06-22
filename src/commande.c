/*
** commande.c for zappy in /home/hammouche/Documents/PSU_2016/zappy/src/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Wed Jun 21 16:07:53 2017 hamza hammouche
** Last update Thu Jun 22 12:28:15 2017 Martin Alais
*/

#include "zappy.h"
#include "Team.h"
#include "Incantation.h"

bool		get_player_team(t_Player *player, char *data, t_Server *serv)
{
  t_team *tmp;
  char		buffer[1256];

  if (strncmp(data, "Exit", 4) == 0)
    return (false);
  if (!player->waitingTeam || serv->list_player)
    return (false);
  if ((tmp = get_team(serv->list_teams, data, -1)) == NULL)
    return (send_message(player->fd, "Ko Team not found\n"), false);
  player->teamId = tmp->id;
  player->waitingTeam = false;
  sprintf(buffer, "%d\n%d %d\n", serv->nbClientMax
	  - get_Player_size(serv->list_player),
	  serv->world->width, serv->world->height);
  send_message(player->fd, buffer);
  return (true);
}

void command_not_found(int id, t_Server *server)
{
  t_Player *tmp;

  tmp = server->list_player;
  while (tmp->next && tmp->id != id)
    tmp = tmp->next;
  send_message(tmp->fd, "KO\n");
}

void exit_client(int id, t_Server *server, char *data)
{
  t_Player *tmp;

  (void) data;
  printf("close client\n");
  tmp = server->list_player;
  while (tmp->next && tmp->id != id)
    tmp = tmp->next;
  tmp->is_connected = false;
  close(tmp->fd);
}

int get_size_commmande(char *str)
{
	int a;

	a = 0;
	while (str[a] != '\0' && str[a] != ' ' && str[a] != '\n')
		a += 1;
	return (a);
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
  command_not_found(id, server);
  return (0);
}
