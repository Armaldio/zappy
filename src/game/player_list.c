/*
** test.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Tue Jun 20 16:02:11 2017 Martin Alais
** Last update Thu Jun 29 10:52:45 2017 Martin Alais
*/

#include "zappy.h"

void my_init_player(t_Player *new, int fd, int id, t_Server *server)
{
  new->fd = fd;
  new->id = id;
  new->controlled = true;
  new->isEgg = false;
  new->is_connected = true;
  // new->pos = get_spaw_pos(server);
  //
  new->pos.x = 0;
  new->pos.y = 0;
  new->gaze = UP;
  new->level = 1;
  init_inventaire(new, server);
  init_action(new);
  ini_waiting_line(new);
  new->life_time = 0;
  new->waitingTeam = true;
  new->death_time = 0;
  new->next = NULL;
  new->isGraphic = false;
  printf("New player connected with fd: %d and id: %d\n", new->fd, new->id);
  printf("Player position: %d %d\n", new->pos.x, new->pos.y);
}

void my_add_player(t_Server *server, int fd)
{
	t_Player *tmp;
	t_Player *new;

	new = my_malloc(sizeof(t_Player));
	tmp = server->list_player;
	if (server->list_player != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
	if (server->list_player == NULL)
		my_init_player(new, fd, 1, server);
	else
		my_init_player(new, fd, tmp->id + 1, server);
	if (server->list_player == NULL)
		server->list_player = new;
	else
		tmp->next = new;
}

void	my_free_player(t_Player *tmp)
{
  if (tmp->inventaire != NULL)
    free(tmp->inventaire);
  if (tmp->waiting_line != NULL && tmp->waiting_line->line != NULL)
    {
      free(tmp->waiting_line->line);
      free(tmp->waiting_line);
    }
  if (tmp->action != NULL && tmp->action->friend_list != NULL)
    {
      free(tmp->action->friend_list);
      free(tmp->action);
    }
}

void my_delete_player(t_Server *server, int id)
{
	t_Player *tmp;
	t_Player *last;
  t_team		*team;

	tmp = server->list_player;
	last = NULL;
	while (tmp != NULL)
	{
		if (tmp->id == id)
		{
			printf("Player with id %d deleted\n", tmp->id);
	  	if ((team = get_team(server->list_teams, NULL, tmp->teamId)) != NULL)
	    	team->nbMember--;
	  	if (last == NULL)
	    	server->list_player = tmp->next;
	  	else
	    	last->next = tmp->next;
	  	my_free_player(tmp);
			free(tmp);
			return;
		}
		last = tmp;
		tmp = tmp->next;
	}
}
