/*
** egg2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Sat Jun 24 15:12:52 2017 Martin Alais
** Last update Sun Jul  2 17:38:14 2017 martin alais
*/

#include "zappy.h"

int		get_eggs_id(t_Server *server)
{
  t_Player	*player;
  int		id;

  id = 1;
  player = server->list_player;
  while (player)
    {
      if (player->isEgg == true)
	id = player->id;
      player = player->next;
    }
  return (id + 1);
}

void	my_init_eggs(t_Player *new, int id, t_Server *server, int father_id)
{
  new->fd = -1;
  new->id = id;
  new->father_id = father_id;
  new->pos = get_spaw_pos(server);
  new->gaze = UP;
  new->level = 1;
  new->is_connected = true;
  new->controlled = false;
  new->isEgg = true;
  init_inventaire(new, server);
  init_action(new);
  ini_waiting_line(new);
  new->life_time = 0;
  new->waitingTeam = true;
  new->death_time = 0;
  new->next = NULL;
  printf("New eggs created by: %d with id: %d\n", new->id, father_id);
  printf("Eggs position: %d %d\n", new->pos.x, new->pos.y);
}

int		my_add_eggs(t_Server *server, t_Player *player)
{
  t_Player	*new;
  t_Player	*last;
  int		eggs_id;

  eggs_id = get_eggs_id(server);
  new = malloc(sizeof(t_Player));
  my_init_eggs(new, eggs_id, server, player->id);
  new->teamId = player->teamId;
  last = server->list_player;
  while (last->next != NULL)
    last = last->next;
  last->next = new;
  return (new->id);
}

t_Player	*get_eggs(int id, t_Player *head)
{
  t_Player	*tmp;

  tmp = head;
  while (tmp && tmp->id != id && tmp->isEgg == false)
    tmp = tmp->next;
  return (tmp);
}
