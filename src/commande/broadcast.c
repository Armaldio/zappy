/*
** command_broadcast.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Thu Jun 22 13:36:04 2017 loic1.doyen@epitech.eu
** Last update Fri Jun 23 14:51:50 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

int command_broadcast(int id, t_Server *server, char *data)
{
  (void)data;
  t_Player	*tmp;

  tmp = server->list_player;
  data = &data[10];
  strcat(data, "\n");
    while (tmp) {
      if (tmp->id == id)
	  stok_answer(tmp, "ok\n");
      else
	  stok_answer(tmp, data);
      tmp = tmp->next;
    }
  return (0);
}
