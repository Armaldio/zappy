/*
** main.c for  in /home/goinau_q/rendu/c/zappy/src/
**
** Made by Quentin Goinaud
** Login   <quentin.goinaud@epitech.eu>
**
** Started on  Tue Jun 20 11:08:35 2017 Quentin Goinaud
** Last update Thu Jun 29 12:44:28 2017 Martin Alais
*/

#include <time.h>
#include "zappy.h"
#include "Server.h"
#include <sys/time.h>

long getMicrotime(){
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

double get_micro(double data)
{
	while (data > 1)
		data -= 1;
	return (data);
}

void	manage_time(t_Server *server)
{
	struct timeval tvTime;

	gettimeofday(&tvTime, NULL);

	int iMilliSec = tvTime.tv_usec / 1000;
	double tmp;

	tmp = (double)iMilliSec / 1000;
	if (tmp < get_micro(server->tmp_time))
		printf("New second\n");

	action_update_time(server, (tmp - get_micro(server->tmp_time)));
	update_player_life(server, (tmp - get_micro(server->tmp_time)));
	server->tmp_time += (tmp - get_micro(server->tmp_time));
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
		end_game(server);
	}
	return (0);
}
