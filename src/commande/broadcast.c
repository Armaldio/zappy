/*
** command_broadcast.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Thu Jun 22 13:36:04 2017 loic1.doyen@epitech.eu
** Last update Fri Jun 30 10:47:16 2017 loic1.doyen@epitech.eu
*/

#include "zappy.h"
#include "Incantation.h"

t_point    perfect_projection(t_World *map, t_Player *a,
			      t_Player *b, t_Server *server)
{
  t_point res;

  start_action(server, a, 1);
  if (abs(b->pos.y - a->pos.y) > (map->height / 2))
    res.y = a->pos.y + abs(a->pos.y - b->pos.y) - map->height;
  else
    res.y = b->pos.y;
  if (abs(b->pos.x - a->pos.x) > (map->width / 2))
    res.x = a->pos.x + abs(a->pos.x - b->pos.x) - map->width;
  else
    res.x = b->pos.x;
  return (res);
}

int	k(t_Player *tmp, t_point res, char **message)
{
  if ((tmp->pos.x - res.x < 0 || res.x < 0) &&
	   (tmp->pos.y - res.y < 0 || res.y < 0))
    sprintf(*message, "message %d", (3 + tmp->gaze * 2) % 8 + 1);
  else if (tmp->pos.x - res.x == 0 && (tmp->pos.y - res.y < 0 || res.y < 0))
    sprintf(*message, "message %d", (4 + tmp->gaze * 2) % 8 + 1);
  else if (bonjour(tmp, res, message));
  else
    return (0);
  return (1);
}

void	ini(t_Player **tmp, t_Player **saying, t_Server *server, int id)
{
  *saying = server->list_player;
  *tmp = server->list_player;
  while (*saying && (*saying)->id != id)
    *saying = (*saying)->next;
}

int		command_broadcast(int id, t_Server *server, char *data)
{
  t_Player	*tmp;
  t_Player	*saying;
  t_point	res;
  char		*message;

  ini(&tmp, &saying, server, id);
  if (strlen(data) < 10)
    return (1);
  message = my_malloc(strlen(data));
  while (tmp) {
      res = perfect_projection(server->world, tmp, saying, server);
      if (tmp->pos.x - res.x == 0 && tmp->pos.y - res.y > 0)
	sprintf(message, "message %d", (0 + tmp->gaze * 2) % 8 + 1);
      else if ((tmp->pos.x - res.x < 0 || res.x < 0) && tmp->pos.y - res.y > 0)
	sprintf(message, "message %d", (1 + tmp->gaze * 2) % 8 + 1);
      else if ((tmp->pos.x - res.x < 0 || res.x < 0) &&
	       tmp->pos.y - res.y == 0)
	sprintf(message, "message %d", (2 + tmp->gaze * 2) % 8 + 1);
      else if (k(tmp, res, &message));
      else
	bonsoir(tmp, res, &message);
      ouais_fini(id, message, data, &tmp);
  }
  free(message);
  return (0);
}
