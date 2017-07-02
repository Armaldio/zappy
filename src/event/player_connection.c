/*
** player_connection.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/event/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Sat Jun 24 11:31:38 2017 Martin Alais
** Last update Sun Jul  2 18:09:08 2017 Martin Alais
*/

#include "Event.h"

void send_all_player(t_Server *server, t_graphic *graphic)
{
	t_Player *player;

	player = server->list_player;
	while (player)
	{
		if (player->isEgg == false && player->controlled == true)
			commande_pnw(server, player, graphic);
		player = player->next;
	}
}

void event_new_player(t_Server *server, t_Player *player)
{
	t_team *team;
	char data[100];
	t_graphic *graphic;

	graphic = server->list_graphic;
	if (graphic == NULL || player == NULL)
		return ;
	memset(data, '\0', 100);
	team = get_team(server->list_teams, NULL, player->teamId);
	if (team == NULL)
		return ;
	sprintf(data, "pnw %d %d %d %d %d %s\n", player->id, player->pos.x,
		player->pos.y, player->gaze + 1, player->level, team->name);
	while (graphic)
	{
		send_message_graphic(graphic, data);
		graphic = graphic->next;
	}
}

void event_conection_for_eggs(t_Server *server, t_Player *player)
{
	char data[100];
	t_graphic *graphic;

	graphic = server->list_graphic;
	sprintf(data, "ebo %d\n", player->id);
	while (graphic)
	{
		send_message_graphic(graphic, data);
		graphic = graphic->next;
	}
}

void event_ppo(t_Server *server, t_Player *player)
{
	char data[100];
	t_graphic *graphic;

	graphic = server->list_graphic;
	sprintf(data, "ppo %d %d %d %d\n", player->id,
	player->pos.x, player->pos.y, player->gaze + 1);
	while (graphic)
	{
		send_message_graphic(graphic, data);
		graphic = graphic->next;
	}
}

void event_take(t_Server *server, t_Player *player, int id_ressource)
{
	char buffer[100];
	char buffer2[100];
	char buffer3[100];
	t_graphic *graphic;

	graphic = server->list_graphic;
	memset(buffer, '\0', 100);
	memset(buffer2, '\0', 100);
	memset(buffer2, '\0', 100);
	sprintf(buffer, "pgt %d %d\n", player->id, id_ressource);
	sprintf(buffer2, "pin %d\n", player->id);
	sprintf(buffer3, "bct %d %d\n", player->pos.x, player->pos.y);
	while (graphic)
	{
		send_message_graphic(graphic, buffer);
		commande_pin(graphic, server, buffer2);
		commande_btc(graphic, server, buffer3);
		graphic = graphic->next;
	}
}
