/*
** player_life.c for life in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Tue Jun 20 15:18:06 2017 Martin Alais
** Last update Tue Jun 27 20:37:53 2017 hamza hammouche
*/

#include "zappy.h"

void		update_player_life(t_Server *server)
{
  t_Player	*tmp;

  tmp = server->list_player;
  while (tmp)
    {
      if (!tmp->isEgg && tmp->waitingTeam == false)
	tmp->life_time += 1;
      tmp = tmp->next;
    }
}

void send_death_message(t_Server *server, t_Player *tmp)
{
  send_message_death(server->list_graphic, tmp->id);
  send_message(tmp->fd, "dead\n");
  close(tmp->fd);
}

void check_player_death(t_Server *server)
{
	t_Player	*tmp;
  t_Player	*tmp2;

	tmp = server->list_player;
	while (tmp)
	{
    tmp2 = tmp->next;
		if (tmp->life_time > tmp->death_time)
		{
			if (tmp->inventaire->food >= 1)
			{
				tmp->inventaire->food -= 1;
				tmp->death_time += my_safe_div(126, server->f);
				printf("player %d eat food !\n", tmp->id);
			}
			else
			{
				printf("Player %d is dead!\n", tmp->id);
	      send_death_message(server, tmp);
				my_delete_player(server, tmp->id);
			}
		}
		tmp = tmp2;
	}
}
