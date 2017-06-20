/*
** Player.c for zappy in /home/hammouche/Documents/PSU_2016/zappy/src/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Tue Jun 20 09:35:13 2017 hamza hammouche
** Last update Tue Jun 20 10:54:08 2017 hamza hammouche
*/

#include "Player.h"

t_Player	*get_Player(int id, t_Player *head)
{
  t_Player *tmp;

	tmp = head;
  while (tmp) {
    if (tmp->id == id)
			return (tmp);
    tmp = tmp->next;
  }
  return (NULL);
}

t_Player	*init_player()
{
	t_Player *player_list;

	player_list = malloc(sizeof(t_Player));
	player_list->next = NULL;
	player_list->is_connected = false;
	player_list->fd = -1;
	player_list->id = 1;
	player_list->pos.x = -1;
	player_list->pos.y = -1;
	return (player_list);
}
