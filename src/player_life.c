/*
** player_life.c for life in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Tue Jun 20 15:18:06 2017 Martin Alais
** Last update Fri Jun 23 10:58:40 2017 hamza hammouche
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

void check_player_death(t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp)
	{
		if (tmp->life_time > tmp->death_time)
		{
			if (tmp->inventaire->food >= 1)
			{
				tmp->inventaire->food -= 1;
				tmp->death_time += (126 / server->f);
				printf("player %d eat food !\n", tmp->id);
			}
			else
			{
				printf("Player %d is dead!\n", tmp->id);
        server->isGraphic == true ? send_message_death(tmp->id, tmp->fd) :
            send_message(tmp->fd, "dead\n");
				close(tmp->fd);
				my_delete_player(server, tmp->id);
			}
		}
		tmp = tmp->next;
	}
}
