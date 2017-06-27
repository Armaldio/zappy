/*
** main.c for  in /home/goinau_q/rendu/c/zappy/src/
**
** Made by Quentin Goinaud
** Login   <quentin.goinaud@epitech.eu>
**
** Started on  Tue Jun 20 11:08:35 2017 Quentin Goinaud
** Last update Tue Jun 27 15:11:29 2017 hamza hammouche
*/

#include <time.h>
#include "zappy.h"
#include "Server.h"

void	manage_time(t_Server *server)
{
  time_t	now;
  struct tm	*tm;

  now = time(0);
  if ((tm = localtime (&now)) == NULL)
    printf ("Error extracting time, no changes\n");
  if (tm->tm_sec != server->fake_time)
    {
      server->fake_time = tm->tm_sec;
      server->time++;
      printf("Elapsed time since start : %ds\n", server->time);
	  action_update_time(server);
	  update_player_life(server);
    }
}

void check_order_player(t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp != NULL)
	{
		if (tmp->is_connected == true && tmp->action->is_working == false)
			parser_commande(tmp->id, server, get_data_from_line(tmp));
		tmp = tmp->next;
	}
}

void	add_default_team(t_Server *server)
{
  t_team *head;

  head = NULL;
  head = add_team(head, "Team1");
  head = add_team(head, "Team2");
  head = add_team(head, "Team3");
  head = add_team(head, "Team4");
  server->list_teams = head;
}

int main(int ac, char **argv)
{
	t_Server *server;

	srand(time(NULL));
	server = my_malloc(sizeof(t_Server));
	basic_init_server(server);
	parser_data(server, ac, argv);
	init_server(server);
  if (server->list_teams == NULL)
    add_default_team(server);
	while (1)
	{
		manage_time(server);
		check_new_player(server);
		check_order_player(server);
		check_action_status(server);
		check_player_death(server);
		check_player_leveling(server);
		my_poll(server);
	}
	return (0);
}
