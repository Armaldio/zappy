/*
** team_status.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/team/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 12:18:48 2017 Martin Alais
** Last update Mon Jun 26 12:59:36 2017 Martin Alais
*/

#include "zappy.h"

bool check_valide_team(char *team_name, t_Server *server,
		       t_undefined *undefine)
{
	t_team *tmp;

	tmp = server->list_teams;
	while (tmp)
	{
		if (strncmp(tmp->name, team_name, strlen(tmp->name)) == 0)
		{
			undefined_to_player(server, undefine, tmp);
			return (true);
		}
		tmp = tmp->next;
	}
	return (false);
}

bool	get_player_team(t_Player *player, char *data, t_Server *serv)
{
  t_team *tmp;
  char		buffer[1256];

  if (player == NULL || player->waitingTeam == false)
    return (false);
  if ((tmp = get_team(serv->list_teams, data, -1)) == NULL)
    return (send_message(player->fd, "ko\n"), true);
  if (serv->nbClientMax < tmp->nbMember + 1)
    return (send_message(player->fd, "ko\n"), true);
  tmp->nbMember++;
  sprintf(buffer, "%d\n%d %d\n", serv->nbClientMax -
	  tmp->nbMember,
	  serv->world->width, serv->world->height);
  player->teamId = tmp->id;
  player->waitingTeam = false;
  send_message(player->fd, buffer);
  return (true);
}
