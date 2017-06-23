/*
** commande_graphic.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/graphic/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 15:55:33 2017 Martin Alais
** Last update Fri Jun 23 15:51:51 2017 hamza hammouche
*/

#include "zappy.h"
#include "Graphic.h"

int		get_random_team(t_Player *player, t_Server *server)
{
  t_team *team;

  team = server->list_teams;
  while (team)
    {
      if (team->nbMember + 1 < server->nbClientMax)
			{
	  		team->nbMember++;
        player->teamId = team->id;
        player->waitingTeam = false;
	  		return (team->id);
			}
      team = team->next;
    }
  return (0);
}

void commande_graphic(t_Player *player, t_Server *server, char *data)
{
  player->isGraphic = true;
  get_random_team(player, server);
	commande_msz(player, server, data);
	commande_sgt(player, server, data);
	commande_mct(player, server, data);
	commande_tna(player, server, data);
	commande_pnw(player, server, data);
}

void commande_mct(t_Player *player, t_Server *server, char *data)
{
	int a;
	int b;

	(void) data;
	a = 0;
	while (a < server->world->height)
	{
		b = 0;
		while (b < server->world->width)
		{
			commande_bct2(server, b, a, player);
			b += 1;
		}
		a += 1;
	}
}
