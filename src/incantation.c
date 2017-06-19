#include "Incantation.h"

void incan_1(int id, t_Server *server)
{
	t_Player *tmp;

	(void) id;
	tmp = server->list_player;
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->inventaire->linemate >= 1)
	{
		tmp->inventaire->linemate -= 1;
		tmp->level += 1;
	}
}

void incan_2(int id, t_Server *server)
{
	(void) id;
	(void) server;
}

void incan_3(int id, t_Server *server)
{
	(void) id;
	(void) server;
}

void incan_4(int id, t_Server *server)
{
	(void) id;
	(void) server;
}

void incan_5(int id, t_Server *server)
{
	(void) id;
	(void) server;
}
