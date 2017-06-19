/*
** Server.h for zappy in /home/hammouche/Documents/PSU_2016/zappy/include/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Mon Jun 19 16:59:53 2017 hamza hammouche
** Last update Mon Jun 19 17:03:34 2017 hamza hammouche
*/

#ifndef ZAPPY_SERVER_H_
# define ZAPPY_SERVER_H_

#include "Player.h"
#include "Socket.h"
#include "World.h"


typedef struct s_Team
{
  int					id;
  char				*name;
  struct s_Team *next;
}							t_team;

typedef struct	s_Server
{
	t_Player *list_player;
	t_Connection *socket;
	t_World *world;
  t_team *list_teams;
}			t_Server;

void init_server(t_Server *server);
void check_new_player(t_Server *server);
void check_client_connection(t_Server *server);
void check_data_player(t_Server *server);
void basic_init_server(t_Server *server);

#endif /* !ZAPPY_SERVER_H_ */
