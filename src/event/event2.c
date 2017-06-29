/*
** event2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/event/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Sat Jun 24 16:00:16 2017 Martin Alais
** Last update Thu Jun 29 16:17:03 2017 Martin Alais
*/

#include "zappy.h"
#include "Event.h"
#include "Graphic.h"

void event_drop(t_Server *server, t_Player *player, int id_ressource)
{
	char buffer[100];
	char buffer2[100];
	char buffer3[100];
	t_graphic *graphic;

	graphic = server->list_graphic;
	memset(buffer, '\0', 100);
	memset(buffer2, '\0', 100);
	memset(buffer2, '\0', 100);
	sprintf(buffer, "pdr %d %d\n", player->id, id_ressource);
	sprintf(buffer2, "pin %d\n", player->id);
	sprintf(buffer3, "bct %d %d\n", player->pos.x, player->pos.y);
	while (graphic)
	{
		send_message(graphic->fd, buffer);
		commande_pin(graphic, server, buffer2);
		commande_btc(graphic, server, buffer3);
		graphic = graphic->next;
	}
}

void event_eject(t_Server *server, t_Player *player)
{
	char buffer2[100];
	t_graphic *graphic;

	graphic = server->list_graphic;
	memset(buffer2, '\0', 100);
	sprintf(buffer2, "pex %d\n", player->id);
	while (graphic)
	{
		send_message(graphic->fd, buffer2);
		graphic = graphic->next;
	}
}

void event_pfk(t_Server *server, t_Player *player)
{
	t_graphic *graphic;
	char buffer2[100];

	memset(buffer2, '\0', 100);
	sprintf(buffer2, "pfk %d\n", player->id);
	graphic = server->list_graphic;
	while (graphic)
	{
		send_message(graphic->fd, buffer2);
		graphic = graphic->next;
	}
}

void event_enw(t_Server *server, int father, t_Player *player)
{
	t_graphic *graphic;
	t_Player *egg_fa;
	char buffer2[100];

	egg_fa = get_Player(father, server->list_player);
	if (egg_fa == NULL)
		return ;
	memset(buffer2, '\0', 100);
	sprintf(buffer2, "enw %d %d %d %d\n", egg_fa->id, player->id,
	player->pos.x, player->pos.y);
	graphic = server->list_graphic;
	while (graphic)
	{
		send_message(graphic->fd, buffer2);
		graphic = graphic->next;
	}
}
