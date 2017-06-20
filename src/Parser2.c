/*
** Parser2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:33:49 2017 Martin Alais
** Last update Tue Jun 20 12:24:27 2017 hamza hammouche
*/

#include "zappy.h"

int parser_nbMax(t_Server *server, char **argv, int a)
{
	int nbr;

	if (argv[a + 1] == NULL)
	{
		printf("[Error] unrecognized argument after -p\n");
		exit(1);
	}
	nbr = atoi(argv[a + 1]);
	if (nbr < 1025)
	{
		printf("[Error] wrong argument after -p\n");
		exit(1);
	}
	server->nbClientMax = nbr;
	return (1);
}

int parser_port(t_Server *server, char **argv, int a)
{
	int nbr;

	if (argv[a + 1] == NULL)
	{
		printf("[Error] unrecognized argument after -p\n");
		exit(1);
	}
	nbr = atoi(argv[a + 1]);
	if (nbr < 1025)
	{
		printf("[Error] wrong argument after -p\n");
		exit(1);
	}
	server->socket->port = nbr;
	return (1);
}

int parser_width(t_Server *server, char **argv, int a)
{
	int nbr;
	if (argv[a + 1] == NULL)
	{
		printf("[Error] unrecognized argument after -x\n");
		exit(1);
	}
	nbr = atoi(argv[a + 1]);
	if (nbr < 1)
	{
		printf("[Error] wrong argument after -x\n");
		exit(1);
	}
	server->world->width = nbr;
	return (1);
}

int parser_height(t_Server *server, char **argv, int a)
{
	int nbr;
	if (argv[a + 1] == NULL)
	{
		printf("[Error] unrecognized argument after -y\n");
		exit(1);
	}
	nbr = atoi(argv[a + 1]);
	if (nbr < 1)
	{
		printf("[Error] wrong argument after -y\n");
		exit(1);
	}
	server->world->height = nbr;
	return (1);
}
