/*
** server_gestion.c for zappy in /home/hammouche/Documents/PSU_2016/zappy/src/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Tue Jun 20 12:29:01 2017 hamza hammouche
** Last update Tue Jun 20 13:43:04 2017 hamza hammouche
*/

#include "Server.h"

t_Player	*delete_player(t_Server *serv, t_Player *player)
{
  t_Player *tmp;

  if (player == NULL)
    return (NULL);
  if (player->is_connected == true || player->fd == -1 ||
      player == serv->list_player)
    return (player->next);
  tmp = serv->list_player;
  while (tmp->next != NULL && tmp->next != player)
    tmp = tmp->next;
  tmp->next = player->next;
  free(player);
  return (tmp->next);
}
