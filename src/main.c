/*
** main.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Tue Jun 20 09:44:44 2017 loic1.doyen@epitech.eu
** Last update Tue Jun 20 09:44:46 2017 loic1.doyen@epitech.eu
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

int main(int ac, char **argv)
{
	t_Server *server;
	int a;

	a = 0;
	(void) ac;
	srand(time(NULL));
	server = my_malloc(sizeof(t_Server));
	basic_init_server(server);
	parser_data(server, argv);
	init_server(server);
	while (1)
	{
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
