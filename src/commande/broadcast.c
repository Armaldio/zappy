/*
** command_broadcast.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Thu Jun 22 13:36:04 2017 loic1.doyen@epitech.eu
** Last update Tue Jun 27 11:08:06 2017 loic1.doyen@epitech.eu
*/

#include "zappy.h"
#include "Incantation.h"

int		command_broadcast(int id, t_Server *server, char *data)
{
  t_Player	*tmp;
  char		*message;

  tmp = server->list_player;
  if (strlen(data) < 10)
    return (1);
  message = my_malloc(strlen(data));
  strcpy(message, ", ");
  strcat(message, &data[10]);
  strcat(message, "\n");
    while (tmp) {
      if (tmp->id == id)
	send_message(tmp->fd, "ok\n");
      else
	{
	  send_message(tmp->fd, "message K");
	  send_message(tmp->fd, message);
	}
      tmp = tmp->next;
    }
  free(message);
  return (0);
}
