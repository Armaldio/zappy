/*
** command_broadcast.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Thu Jun 22 13:36:04 2017 loic1.doyen@epitech.eu
** Last update Thu Jun 22 13:51:25 2017 loic1.doyen@epitech.eu
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
	send_message(tmp->fd, "OK\n");
      else
	send_message(tmp->fd, data);
      tmp = tmp->next;
    }
  return (0);
}
