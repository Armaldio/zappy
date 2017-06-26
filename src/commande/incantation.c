/*
** incantation.c for zappy.h in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:07:57 2017 Martin Alais
** Last update Mon Jun 26 13:08:27 2017 Martin Alais
*/

#include "zappy.h"

void commande_incantation(int id, t_Server *server, char data)
{
	t_Player *tmp;
  t_Player	*ptmp;
  char			buffer[2048];
  char			nb[15];

	(void) data;
  ptmp = server->list_player;
  tmp = get_Player(id, server->list_player);
	start_action(server, tmp, 300);
	tmp->action->is_leveling = true;
  sprintf(buffer, "pic %d %d %d %d", tmp->pos.x, tmp->pos.y, tmp->level,
	  tmp->id);
  while (ptmp)
    {
      if (ptmp != tmp)
			{
	  		sprintf(nb, " %d", ptmp->id);
	  		strcat(buffer, nb);
			}
      ptmp = ptmp->next;
    }
  strcat(buffer, "\n");
  send_message_position(server->list_graphic, buffer);
}
