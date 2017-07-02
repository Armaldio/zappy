/*
** inventory.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:34:48 2017 Martin Alais
** Last update Sun Jul  2 14:49:53 2017 martin alais
*/

#include "zappy.h"

void		command_inventory(int id, t_Server *server, char *data)
{
  char		send_data[4096];
  t_Player	*tmp;
  
  (void) data;
  tmp = get_Player(id, server->list_player);
  if (check_valide_commande(tmp, 9, data))
    return ;
  start_action(server, tmp, 1);
  memset(send_data, '\0', 4096);
  sprintf(send_data, "[food %d, linemate %d, deraumere %d, sibur %d, \
mendiane %d, phiras %d, thystane %d]\n", tmp->inventaire->food,
	  tmp->inventaire->linemate, tmp->inventaire->deraumere,
	  tmp->inventaire->sibur, tmp->inventaire->mendiane,
	  tmp->inventaire->phiras, tmp->inventaire->thystane);
  stok_answer(tmp, send_data);
}
