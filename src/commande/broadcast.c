/*
** command_broadcast.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Thu Jun 22 13:36:04 2017 loic1.doyen@epitech.eu
** Last update Tue Jun 27 11:36:57 2017 loic1.doyen@epitech.eu
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
  strcpy(message, "message K, ");
  strcat(message, &data[10]);
  strcat(message, "\n");
    while (tmp) {
      start_action(server, tmp, 1);
      if (tmp->id == id)
	stok_answer(tmp, "ok\n");
      else
	stok_answer(tmp, message);
      tmp = tmp->next;
    }
  free(message);
  return (0);
}
