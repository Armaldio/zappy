#include <time.h>
#include "zappy.h"
#include "Server.h"
int main(int ac, char **argv)
{
	t_Server *server;

	(void) ac;
	(void) argv;
	srand(time(NULL));
	server = my_malloc(sizeof(t_Server));
	basic_init_server(server);
	parser_data(server, argv);
	init_server(server);
	while(1)
	{
		check_new_player(server);
		check_data_player(server);
	}
}
