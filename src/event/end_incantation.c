/*
** end_incantation.c for zappy in /home/hammouche/Documents/PSU_2016/zappy/src/event/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Mon Jun 26 12:23:19 2017 hamza hammouche
** Last update Mon Jun 26 15:52:47 2017 hamza hammouche
*/

#include "zappy.h"
#include "Event.h"
#include "Graphic.h"

void	send_message_bct(t_Server *serv, t_graphic *head, t_Player *player)
{
  t_graphic	*tmp;

  tmp = head;
  while (tmp)
    {
      commande_bct2(serv, player->pos.x, player->pos.y, tmp);
      tmp = tmp->next;
    }
}

void	send_message_plv(t_graphic *head, t_Player *hlist, t_Player *p)
{
  t_graphic	*tmp;
  t_Player	*ptmp;
  char			buffer[200];

  tmp = head;
  while (tmp)
    {
      ptmp = hlist;
      while (ptmp)
			{
	  		if (ptmp->pos.x == p->pos.x && ptmp->pos.y == p->pos.y)
	    	{
          memset(buffer, '\0', 200);
          sprintf(buffer, "plv %d %d", ptmp->id, ptmp->level);
  	  		send_message(tmp->fd, buffer);
	    	}
	  		ptmp = ptmp->next;
			}
      tmp = tmp->next;
    }
}

void	event_endI(t_Server *server, t_Player *player)
{
  send_message_pie(server->list_graphic, player);
  send_message_plv(server->list_graphic, server->list_player, player);
  send_message_bct(server, server->list_graphic, player);
}
