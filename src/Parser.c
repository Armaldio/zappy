#include "zappy.h"

void parser_data2(int b, int *a, t_Server *server, char **argv)
{
	void	*mfunction_ptr[] = {parser_port, parser_width, parser_height,
  parser_team, NULL};
	int	(*fct_ptr)(t_Server *, char **, int);

	fct_ptr = mfunction_ptr[b];
	*a += fct_ptr(server, argv, *a);

}

void print_parse_error(char *data)
{
	printf("[Error] unrecognized argument:  %s\n", data);
	exit(1);
}

void parser_data(t_Server *server, char **argv)
{
	int a;
	int b;
	char	*mcommand[] = {"-p", "-x", "-y", "-n", "-f", "-c", NULL};

	bool found;

	a = 1;
	while (argv[a])
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
