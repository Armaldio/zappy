/*
** broadcast2.c for  in /home/macdoy/Rendu/zappy/src/commande/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Fri Jun 30 10:43:08 2017 loic1.doyen@epitech.eu
** Last update Fri Jun 30 10:44:03 2017 loic1.doyen@epitech.eu
*/

#include "zappy.h"
#include "Incantation.h"

void	bonsoir(t_Player *tmp, t_point res, char **message)
{
  if (tmp->pos.x - res.x > 0 && tmp->pos.y - res.y > 0)
    sprintf(*message, "message %d", (7 + tmp->gaze * 2) % 8 + 1);
  else
    sprintf(*message, "message %d", 0);
}

int	bonjour(t_Player *tmp, t_point res, char **message)
{
  if (tmp->pos.x - res.x > 0 && (tmp->pos.y - res.y < 0 || res.y < 0))
    sprintf(*message, "message %d", (5 + tmp->gaze * 2) % 8 + 1);
  else if (tmp->pos.x - res.x > 0 && tmp->pos.y - res.y == 0)
    sprintf(*message, "message %d", (6 + tmp->gaze * 2) % 8 + 1);
  else
    return (0);
  return (1);
}

void	ouais_fini(int id, char *message, char *data, t_Player **tmp)
{
  strcat(message, ", ");
  strcat(message, &data[10]);
  strcat(message, "\n");
  if ((*tmp)->id == id)
    stok_answer(*tmp, "ok\n");
  else
    stok_answer(*tmp, message);
  *tmp = (*tmp)->next;
}
