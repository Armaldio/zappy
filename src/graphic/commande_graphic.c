/*
** commande_graphic.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/graphic/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 15:55:33 2017 Martin Alais
** Last update Thu Jun 22 17:46:25 2017 Martin Alais
*/

#include "zappy.h"
#include "Graphic.h"

void commande_graphic(t_Player *player, t_Server *server, char *data)
{
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
