/*
** commande_graphic.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/graphic/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 15:55:33 2017 Martin Alais
** Last update Sun Jul  2 23:46:56 2017 Quentin Goinaud
*/

#include "zappy.h"
#include "Graphic.h"

int		get_random_team(t_Player *player, t_Server *server)
{
  t_team	*team;

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

void		my_pnw(t_graphic *graphic, t_Server *server, char *data)
{
  t_Player	*player;

  (void) data;
  player = server->list_player;
  while (player)
    {
      if (player->id_eggs == false && player->controlled == true)
	commande_pnw(server, player, graphic);
      player = player->next;
    }
}

void		my_enw(t_graphic *graphic, t_Server *server, char *data)
{
  t_Player	*egg_fa;
  char		buffer2[100];
  t_Player	*player;

  (void) data;
  player = server->list_player;
  while (player)
    {
      if (player->isEgg == true)
	{
	  egg_fa = get_Player(player->father_id, server->list_player);
	  if (egg_fa == NULL)
	    return ;
	  memset(buffer2, '\0', 100);
	  sprintf(buffer2, "enw %d %d %d %d\n", player->id, egg_fa->id,
		  player->pos.x, player->pos.y);
	  send_message_graphic(graphic, buffer2);
	}
      player = player->next;
    }
}

void	commande_graphic(t_graphic *player, t_Server *server, char *data)
{
  commande_msz(player, server, data);
  commande_sgt(player, server, data);
  commande_mct(player, server, data);
  commande_tna(player, server, data);
  //my_pnw(player, server, data);
  my_enw(player, server, data);
}

void	commande_mct(t_graphic *player, t_Server *server, char *data)
{
  int	a;
  int	b;

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
