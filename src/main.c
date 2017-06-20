/*
** main.c for  in /home/goinau_q/rendu/c/zappy/src/
**
** Made by Quentin Goinaud
** Login   <quentin.goinaud@epitech.eu>
**
** Started on  Tue Jun 20 11:08:35 2017 Quentin Goinaud
** Last update Tue Jun 20 11:08:38 2017 Quentin Goinaud
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

void print_inventaire_player(t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next != NULL)
	{
		printf("Player id: %d\n", tmp->id);
		printf("deraumere: %d\n", tmp->inventaire->deraumere);
		printf("linemate: %d\n", tmp->inventaire->linemate);
		printf("mendiane: %d\n", tmp->inventaire->mendiane);
		printf("phiras: %d\n", tmp->inventaire->phiras);
		printf("sibur: %d\n", tmp->inventaire->sibur);
		printf("thystane: %d\n\n", tmp->inventaire->thystane);
		tmp = tmp->next;
	}
	printf("Player id: %d\n", tmp->id);
	printf("deraumere: %d\n", tmp->inventaire->deraumere);
	printf("linemate: %d\n", tmp->inventaire->linemate);
	printf("mendiane: %d\n", tmp->inventaire->mendiane);
	printf("phiras: %d\n", tmp->inventaire->phiras);
	printf("sibur: %d\n", tmp->inventaire->sibur);
	printf("thystane: %d\n\n", tmp->inventaire->thystane);
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
    }
}

int main(int ac, char **argv)
{
	t_Server *server;
	int a;

	a = 0;
	srand(time(NULL));
	server = my_malloc(sizeof(t_Server));
	basic_init_server(server);
	parser_data(server, ac, argv);
	init_server(server);
	while (1)
	{
		manage_time(server);
		check_new_player(server);
		check_data_player(server);
		if (DEBUG)
		{
			if ((a % 10) == 0)
			{
				print_inventaire_player(server);
				print_player(server);
			}
			a += 1;
		}
	}
	return (0);
}
