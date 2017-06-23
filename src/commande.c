/*
** commande.c for zappy in /home/hammouche/Documents/PSU_2016/zappy/src/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Wed Jun 21 16:07:53 2017 hamza hammouche
** Last update Fri Jun 23 14:56:51 2017 hamza hammouche
*/

#include "zappy.h"
#include "Team.h"
#include "Incantation.h"

bool		get_player_team(t_Player *player, char *data, t_Server *serv)
{
  t_team *tmp;
  char		buffer[1256];

  if (strncmp(data, "Exit", 4) == 0 || strncmp(data, "GRAPHIC", 7) == 0)
    return (false);
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
  my_delete_player(server, tmp->id);
}

void command_pos(int id, t_Server *server, char *data)
{
	t_Player *player;
	char data_send[200];

	(void) data;
	player = get_Player(id, server->list_player);
	sprintf(data_send, "%d - %d\n", player->pos.x, player->pos.y);
	send_message(player->fd, data_send);
}

void eject_player(t_Server *server, t_Player *player)
{
	if (player->gaze == UP)
	{
		go_up(server, player->id, false);
		send_message(player->fd, "eject: 1\n");
	}
	else if (player->gaze == DOWN)
	{
		go_down(server, player->id, false);
		send_message(player->fd, "eject: 3\n");
	}
	else if (player->gaze == RIGHT)
	{
		go_right(server, player->id, false);
		send_message(player->fd, "eject: 2\n");
	}
	else
	{
		go_left(server, player->id, false);
		send_message(player->fd, "eject: 4\n");
	}
}

void command_eject(int id, t_Server *server, char *data)
{
	t_Player *tmp;
	t_Player *player;
  char buffer[512];

	(void) data;
	player = get_Player(id, server->list_player);
	tmp = server->list_player;
	start_action(server, player, 7);
	while (tmp)
	{
		if (tmp->id != player->id && tmp->pos.x == player->pos.x
		    && tmp->pos.y == player->pos.y)
		{
			printf("Player %d ejected by player %d !\n", tmp->id, player->id);
			eject_player(server, tmp);
		}
		tmp = tmp->next;
	}
  sprintf(buffer, "pex %d\n", id);
  player->isGraphic == true ? send_message(tmp->fd, buffer) :
      send_message(tmp->fd, "ok\n");
}
