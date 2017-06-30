/*
** poll4.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/game/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Fri Jun 30 15:43:39 2017 Martin Alais
** Last update Fri Jun 30 15:47:21 2017 Martin Alais
*/

#include "zappy.h"
#include "unix_cbuffer.h"

void complete_read_graphic(t_graphic *tmp3, char *data_recv, t_Server *server)
{
	int a;

	a = zappy_getline(tmp3->read_buffer, data_recv);
	strcat(data_recv, "\n");
	printf("%d: %s", tmp3->id, data_recv);
	graphic_parser(tmp3->id, server, data_recv);
	memset(data_recv, '\0', 4095);
	while (a > 0)
	{
		a = zappy_getline(tmp3->read_buffer, data_recv);
		if (a != 0)
		{
			strcat(data_recv, "\n");
			printf("%d: %s", tmp3->id, data_recv);
			graphic_parser(tmp3->id, server, data_recv);
			memset(data_recv, '\0', 4095);
		}
	}
}
