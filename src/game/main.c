/*
** main.c for  in /home/goinau_q/rendu/c/zappy/src/
**
** Made by Quentin Goinaud
** Login   <quentin.goinaud@epitech.eu>
**
** Started on  Tue Jun 20 11:08:35 2017 Quentin Goinaud
** Last update Thu Jun 29 12:09:32 2017 Martin Alais
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
	time_t	now;
	struct tm	*tm;

	struct timeval tvTime;

	gettimeofday(&tvTime, NULL);

	int iTotal_seconds = tvTime.tv_sec;
	struct tm *ptm = localtime((const time_t *) & iTotal_seconds);

	int iHour = ptm->tm_hour;;
	int iMinute = ptm->tm_min;
	int iSecond = ptm->tm_sec;
	int iMilliSec = tvTime.tv_usec / 1000;
	int iMicroSec = tvTime.tv_usec;

	double time_time = tvTime.tv_usec / 1000000;
	double res_all = server->fake_time - time_time;

	// printf("Time: %d %d %d %d %d\n", iHour, iMinute, iSecond, iMilliSec, iMicroSec);
	// printf("localtime: %d\n", server->fake_time);
	// printf("CALC : %lf %lf", server->fake_time, time_time);
	double tmp;

	tmp = (double)iMilliSec / 1000;
	// printf("Time Elapsed: %lf\n",  tmp);

	printf("comapring %lf and %lf\n", tmp, get_micro(server->tmp_time));
	if (tmp < get_micro(server->tmp_time))
		printf("New second\n");

	server->tmp_time += (tmp - get_micro(server->tmp_time));

	// server->fake_time += tmp;
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
		end_game(server);
	}
	return (0);
}
