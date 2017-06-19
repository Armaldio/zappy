#include "zappy.h"

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
	return(1);
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
	return(1);
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
	return(1);
}

void parser_data(t_Server *server, char **argv)
{
	int a;
	int b;
	char	*mcommand[] = {"-p", "-x", "-y", "-c", "-f", NULL};
	void	*mfunction_ptr[] = {parser_port, parser_width, parser_height, NULL};
	int	(*fct_ptr)(t_Server *, char **, int);
	bool found;

	a = 1;
	while (argv[a])
	{
		b = 0;
		found = false;
		while(mcommand[b])
		{
			if (strncmp(mcommand[b], argv[a], strlen(mcommand[b])) == 0)
			{
				fct_ptr = mfunction_ptr[b];
				a += fct_ptr(server, argv, a);
				found = true;
			}
			b += 1;
		}
		if (found == false)
		{
			printf("[Error] unrecognized argument:  %s\n", argv[a]);
			exit(1);
		}
		a += 1;
	}
}
