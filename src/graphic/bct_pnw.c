/*
** bct.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/graphic/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 16:29:47 2017 Martin Alais
** Last update Fri Jun 23 19:45:02 2017 Martin Alais
*/

#include "zappy.h"
#include "Graphic.h"

void commande_bct2(t_Server *server, int x, int y, t_graphic *player)
{
	char data[100];
	memset(data, '\0', 100);
	sprintf(data, "btc %d %d %d %d %d %d %d %d %d\n", x, y,
	server->world->map[x][y]->food, server->world->map[x][y]->linemate,
	server->world->map[x][y]->deraumere, server->world->map[x][y]->sibur,
	server->world->map[x][y]->mendiane, server->world->map[x][y]->phiras,
	server->world->map[x][y]->thystane);
	send_message(player->fd, data);
}

void commande_pnw(t_Server *server, int id)
{
	t_graphic *tmp;
	t_Player *player;
	t_team *team;
	char data[100];

	player = get_Player(id, server->list_player);
	team = get_team(server->list_teams, NULL, player->teamId);
	tmp = server->list_graphic;
	sprintf(data, "pnw %d %d %d %d %d %s\n", player->id, player->pos.x,
		player->pos.y, player->gaze + 1, player->level, team->name);
	while (tmp)
	{
		send_message(tmp->fd, data);
		tmp = tmp->next;
	}
}

char **init_res(char *data)
{
	char **res;

	res = malloc(sizeof(char *) * 3);
	res[0] = malloc(sizeof(char) * strlen(data));
	memset(res[0], '\0', strlen(data));
	res[1] = malloc(sizeof(char) * strlen(data));
	memset(res[1], '\0', strlen(data));
	res[2] = NULL;
	return (res);
}

char **split_nbr(char *data)
{
	char **res;
	int a;
	int b;
	int c;

	res = init_res(data);
	a = 0;
	b = 0;
	c = 0;
	while (data[c])
	{
		if (data[c] == ' ' && b == 0)
		{
			b += 1;
			a = 0;
		}
		else
		{
			res[b][a] = data[c];
			a += 1;
		}
		c += 1;
	}
	return (res);
}

void commande_btc(t_graphic *player, t_Server *server, char *data)
{
	char **nbr;

	data += 4;
	nbr = split_nbr(data);
	commande_bct2(server, atoi(nbr[0]), atoi(nbr[1]), player);
	free(nbr[0]);
	free(nbr[1]);
	free(nbr);
}
