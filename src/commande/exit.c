/*
** exit.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 12:59:57 2017 Martin Alais
** Last update Sun Jul  2 14:46:12 2017 martin alais
*/

#include "zappy.h"

void		exit_client(int id, t_Server *server, char *data)
{
  t_Player	*tmp;

  (void) data;
  printf("close client\n");
  tmp = server->list_player;
  while (tmp->next && tmp->id != id)
    tmp = tmp->next;
  tmp->is_connected = false;
  close(tmp->fd);
  my_delete_player(server, tmp->id);
}
