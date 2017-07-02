/*
** event3.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/event/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Sun Jun 25 11:47:58 2017 Martin Alais
** Last update Sun Jul  2 18:08:24 2017 martin alais
*/

#include "zappy.h"
#include "Event.h"

void		event_eht(t_Server *server, t_Player *player)
{
  t_graphic	*graphic;
  char		buffer2[100];

  memset(buffer2, '\0', 100);
  sprintf(buffer2, "eht %d\n", player->id);
  graphic = server->list_graphic;
  while (graphic)
    {
      send_message_graphic(graphic, buffer2);
      graphic = graphic->next;
    }
}
