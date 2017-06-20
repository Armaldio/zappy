/*
** Parser.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Tue Jun 20 09:44:59 2017 loic1.doyen@epitech.eu
** Last update Tue Jun 20 12:21:40 2017 hamza hammouche
*/

#include "zappy.h"

void parser_data2(int b, int *a, t_Server *server, char **argv)
{
	void	*mfunction_ptr[] = {parser_port, parser_width, parser_height,
  parser_team, parser_nbMax, NULL};
	int	(*fct_ptr)(t_Server *, char **, int);

	fct_ptr = mfunction_ptr[b];
	*a += fct_ptr(server, argv, *a);

}

void print_parse_error(char *data)
{
	printf("[Error] unrecognized argument:  %s\n", data);
	exit(1);
}

void parser_data(t_Server *server, int ac, char **argv)
{
	int a;
	int b;
	char	*mcommand[] = {"-p", "-x", "-y", "-n", "-c", "-f", NULL};
	bool found;

	a = 1;
	while (a < ac)
	{
		b = 0;
		found = false;
		while (mcommand[b])
		{
			if (strncmp(mcommand[b], argv[a], strlen(mcommand[b])) == 0)
			{
				parser_data2(b, &a, server, argv);
				found = true;
			}
			b += 1;
		}
		if (found == false)
			print_parse_error(argv[a]);
		a += 1;
	}
}
