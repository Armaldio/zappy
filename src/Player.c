/*
** Player.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Tue Jun 20 09:45:06 2017 loic1.doyen@epitech.eu
** Last update Tue Jun 20 09:45:07 2017 loic1.doyen@epitech.eu
*/

#include "Player.h"

t_Player *init_player()
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
