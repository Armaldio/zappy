/*
** commande.c for zappy in /home/hammouche/Documents/PSU_2016/zappy/src/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Tue Jun 20 09:44:32 2017 loic1.doyen@epitech.eu
** Last update Tue Jun 20 10:59:29 2017 loic1.doyen@epitech.eu
*/

#include "zappy.h"
#include "Team.h"
#include "Incantation.h"

bool		get_player_team(t_Player *player, char *data, t_Server *serv)
{
  t_team *tmp;

  if (!player->waitingTeam)
    return (false);
  if ((tmp = get_team(serv->list_teams, data, -1)) == NULL)
    return (false);
  player->teamId = tmp->id;
  player->waitingTeam = false;
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

int parser_commande(int id, t_Server *server, char *data)
{
	char	*mcommand[] = {"Forward", "Right", "Left",
	"Incantation", "Take", "Look", NULL};
	void	*mfunction_ptr[] = {commande_forward, commande_right,
		commande_left, commande_incantation, command_take, command_look, NULL};
	void	(*fct_ptr)(int, t_Server *, char *);
	int		a;

	a = 0;
  if (get_player_team(get_Player(id, server->list_player), data, server))
    return (0);
	while (mcommand[a])
	{
		if (strncmp(mcommand[a], data, strlen(mcommand[a])) == 0)
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
