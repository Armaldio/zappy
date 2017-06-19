#ifndef ZAPPY_SERVER_H_
# define ZAPPY_SERVER_H_

#include "Player.h"
#include "Socket.h"
#include "World.h"

typedef struct	s_Server
{
	t_Player *list_player;
	t_Connection *socket;
	t_World *world;
}			t_Server;

void init_server(t_Server *server);
void check_new_player(t_Server *server);
void check_client_connection(t_Server *server);
void check_data_player(t_Server *server);
void basic_init_server(t_Server *server);
void take_linemate(int id, t_Server *server);
void take_deraumere(int id, t_Server *server);
void take_sibur(int id, t_Server *server);
void take_mendiane(int id, t_Server *server);
void take_phiras(int id, t_Server *server);
void take_thystane(int id, t_Server *server);

#endif /* !ZAPPY_SERVER_H_ */
