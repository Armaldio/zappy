/*
** zappy.h for zappy in /home/alaism/dev/tek2/PSU/zappy/include/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:00:24 2017 Martin Alais
** Last update Tue Jun 20 10:53:30 2017 loic1.doyen@epitech.eu
*/

#ifndef ZAPPY_MAIN_H_
# define ZAPPY_MAIN_H_

#include "Server.h"
#include "mouvement.h"

# define DEBUG 0

void parser_data(t_Server *server, int ac, char **argv);
int	parser_team(t_Server *serv, char **argv, int a);
int parser_commande(int id, t_Server *server, char *data);
void commande_forward(int id, t_Server *server, char *data);
void commande_right(int id, t_Server *server, char *data);
void commande_left(int id, t_Server *server, char *data);
void commande_incantation(int id, t_Server *server, char data);
int command_take(int id, t_Server *server, char *data);
int command_look(int id, t_Server *server, char *data);
int parser_port(t_Server *server, char **argv, int a);
int parser_width(t_Server *server, char **argv, int a);
int parser_height(t_Server *server, char **argv, int a);


#endif /* !ZAPPY_MAIN_H_ */
