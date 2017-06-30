/*
** ppo_plv_pin.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/graphic/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 18:05:16 2017 Martin Alais
** Last update Fri Jun 30 09:36:30 2017 hamza hammouche
*/

#include "zappy.h"
#include "Graphic.h"

void commande_ppo(t_graphic *player, t_Server *server, char *data2)
{
	char data[100];
	int id;
	t_Player *tmp;

	data2 += 4;
	id = atoi(data2);
	if (id <= 0)
	{
		send_message(player->fd, "sbp\n");
		return ;
	}
	tmp = get_Player(id, server->list_player);
	memset(data, '\0', 100);
	sprintf(data, "ppo %d %d %d %d\n", tmp->id,
	tmp->pos.x, tmp->pos.y, tmp->gaze + 1);
	send_message(player->fd, data);
}

void commande_plv(t_graphic *player, t_Server *server, char *data2)
{
	char data[100];
	int id;
	t_Player *tmp;

	data2 += 4;
	id = atoi(data2);
	if (id <= 0)
	{
		send_message(player->fd, "sbp\n");
		return ;
	}
	tmp = get_Player(id, server->list_player);
	memset(data, '\0', 100);
	sprintf(data, "plv %d %d\n", tmp->id, tmp->level);
	send_message(player->fd, data);
}

void commande_pin(t_graphic *player, t_Server *server, char *data2)
{
	char data[300];
	int id;
	t_Player *tmp;

	data2 += 4;
	id = atoi(data2);
	if (id <= 0)
	{
		send_message(player->fd, "sbp\n");
		return ;
	}
	tmp = get_Player(id, server->list_player);
	memset(data, '\0', 300);
	sprintf(data, "pin %d %d %d %d %d %d %d %d %d %d\n",
	tmp->id, tmp->inventaire->food, tmp->pos.x, tmp->pos.y,
	tmp->inventaire->linemate, tmp->inventaire->deraumere,
	tmp->inventaire->sibur, tmp->inventaire->mendiane,
	tmp->inventaire->phiras, tmp->inventaire->thystane);
	send_message(player->fd, data);
}

void	commande_pin_graph(t_graphic *head, t_Player *player)
{
  t_graphic	*tmp;
  char			data[300];

  tmp = head;
	memset(data, '\0', 300);
	sprintf(data, "pin %d %d %d %d %d %d %d %d %d %d\n",
	player->id, player->inventaire->food, player->pos.x, player->pos.y,
	player->inventaire->linemate, player->inventaire->deraumere,
	player->inventaire->sibur, player->inventaire->mendiane,
	player->inventaire->phiras, player->inventaire->thystane);
  while (tmp)
    {
			send_message(tmp->fd, data);
      tmp = tmp->next;
    }
}
