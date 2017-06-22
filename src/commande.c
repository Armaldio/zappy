/*
** commande.c for zappy in /home/hammouche/Documents/PSU_2016/zappy/src/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Wed Jun 21 16:07:53 2017 hamza hammouche
** Last update Thu Jun 22 14:19:04 2017 loic1.doyen@epitech.eu
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

void command_pos(int id, t_Server *server, char *data)
{
	t_Player *player;
	char data_send[200];

	(void) data;
	player = get_Player(id, server->list_player);
	sprintf(data_send, "Eject %d, %d\n", player->pos.x, player->pos.y);
	send_message(player->fd, data_send);
}

void eject_player(t_Server *server, t_Player *player)
{
	if (player->gaze == UP)
		go_up(server, player->id);
	else if (player->gaze == DOWN)
		go_down(server, player->id);
	else if (player->gaze == RIGHT)
		go_right(server, player->id);
	else
		go_left(server, player->id);
}

void command_eject(int id, t_Server *server, char *data)
{
	t_Player *tmp;
	t_Player *player;

	(void) data;
	player = server->list_player;
	tmp = server->list_player;
	while (player->next && player->id != id)
		player = player->next;
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
}
