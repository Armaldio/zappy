/*
** commande3.c for  in /home/goinau_q/rendu/c/zappy/src/
**
** Made by Quentin Goinaud
** Login   <quentin.goinaud@epitech.eu>
**
** Started on  Wed Jun 21 13:56:20 2017 Quentin Goinaud
** Last update Thu Jun 22 11:07:21 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

void command_fork(int id, t_Server *server, char *data)
{
  t_Player	*tmp;
  int		egg_id;

  (void) id;
  (void) data;
  egg_id = my_add_player_id(server, -1);
  tmp = server->list_player;
  while (tmp->next && tmp->id != egg_id)
    tmp = tmp->next;
  tmp->is_connected = true;
  tmp->controlled = false;
  tmp->isEgg = true;
  tmp->pos = get_spaw_pos(server);
  start_action(server, tmp, 42);
  add_data_in_line(tmp, "Hatch");
}

void command_hatch(int id, t_Server *server, char *data)
{
  t_Player	*tmp;

  (void) data;
  tmp = server->list_player;
  while (tmp->next && tmp->id != id)
    tmp = tmp->next;
  start_action(server, tmp, 600);
  add_data_in_line(tmp, "Bloom");
}

void command_bloom(int id, t_Server *server, char *data)
{
  t_Player	*tmp;

  (void) data;
  tmp = server->list_player;
  while (tmp->next && tmp->id != id)
    tmp = tmp->next;
  tmp->gaze = rand() % 4;
  tmp->isEgg = false;
  tmp->is_connected = false;
}
