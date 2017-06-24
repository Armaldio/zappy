/*
** main.c for  in /home/goinau_q/rendu/c/zappy/src/
**
** Made by Quentin Goinaud
** Login   <quentin.goinaud@epitech.eu>
**
** Started on  Tue Jun 20 11:08:35 2017 Quentin Goinaud
** Last update Sat Jun 24 11:13:31 2017 Martin Alais
*/

#include <time.h>
#include "zappy.h"
#include "Server.h"

void print_player(t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next != NULL)
	{
		printf("Player id: %d\n", tmp->id);
		printf("pos_x: %d\n", tmp->pos.x);
		printf("pos_y: %d\n\n", tmp->pos.y);
		tmp = tmp->next;
	}
	printf("Player id: %d\n", tmp->id);
	printf("pos_x: %d\n", tmp->pos.x);
	printf("pos_y: %d\n\n", tmp->pos.y);
}

bool check_valide_team(char *team_name, t_Server *server, t_undefined *undefine)
{
	t_team *tmp;

	tmp = server->list_teams;
	while (tmp)
	{
		if (strncmp(tmp->name, team_name, strlen(tmp->name)) == 0)
		{
			undefined_to_player(server, undefine, tmp);
			return(true);
		}
		tmp = tmp->next;
	}
	return(false);
}

void check_data_undefine(t_undefined *tmp, char *data_recv, int a, t_Server *server)
{
	if (a == 0)
	{
		printf("Undefined with id %d disconected\n", tmp->id);
		delete_undefine(server, tmp->id);
	}
	else
	{
		if (strcmp(data_recv, "GRAPHIC\n") == 0)
			undefined_to_graphic(server, tmp);
		else if (check_valide_team(data_recv, server, tmp) != true)
			send_message(tmp->fd, "ko\n");
	}
}

void check_undefine(t_Server *server)
{
	int a;
	char data_recv[4096];
	struct timeval tv;
	t_undefined *tmp;
	fd_set rfds;

	tmp = server->list_undefined;
	memset(data_recv, '\0', 4096);
	while (tmp != NULL)
	{
		FD_ZERO(&rfds);
		FD_SET(tmp->fd, &rfds);
		tv.tv_sec = 0;
		tv.tv_usec = 300;
		a = select(tmp->fd + 1, &rfds, NULL, NULL, &tv);
		if (a != 0)
		{
			a = recv(tmp->fd, data_recv, 4095, MSG_DONTWAIT);
			check_data_undefine(tmp, data_recv, a, server);
			memset(data_recv, '\0', 4096);
		}
		tmp = tmp->next;
	}
}

void check_graphique(t_Server *server)
{
	int a;
	char data_recv[4096];
	struct timeval tv;
	t_graphic *tmp;
	fd_set rfds;

	tmp = server->list_graphic;
	memset(data_recv, '\0', 4096);
	while (tmp != NULL)
	{
		FD_ZERO(&rfds);
		FD_SET(tmp->fd, &rfds);
		tv.tv_sec = 0;
		tv.tv_usec = 300;
		a = select(tmp->fd + 1, &rfds, NULL, NULL, &tv);
		if (a != 0)
		{
			a = recv(tmp->fd, data_recv, 4095, MSG_DONTWAIT);
			graphic_parser(tmp->id, server, data_recv);
			memset(data_recv, '\0', 4096);
		}
		tmp = tmp->next;
	}
}

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

int main(int ac, char **argv)
{
	t_Server *server;

	srand(time(NULL));
	server = my_malloc(sizeof(t_Server));
	basic_init_server(server);
	parser_data(server, ac, argv);
	init_server(server);
	while (1)
	{
		manage_time(server);
		check_new_player(server);
		check_order_player(server);
		check_data_player(server);
		check_action_status(server);
		check_player_death(server);
		check_player_leveling(server);
		check_undefine(server);
		check_graphique(server);
	}
	return (0);
}
