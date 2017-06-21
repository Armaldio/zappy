/*
** zappy.h for zappy in /home/alaism/dev/tek2/PSU/zappy/include/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:00:24 2017 Martin Alais
** Last update Wed Jun 21 15:03:08 2017 Quentin Goinaud
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
void	command_fork(int id, t_Server *server, char *data);
void	command_hatch(int id, t_Server *server, char *data);
void	command_bloom(int id, t_Server *server, char *data);
int command_take(int id, t_Server *server, char *data);
int command_look(int id, t_Server *server, char *data);
int parser_nbMax(t_Server *server, char **argv, int a);
int parser_port(t_Server *server, char **argv, int a);
int parser_width(t_Server *server, char **argv, int a);
int parser_height(t_Server *server, char **argv, int a);
int parser_freq(t_Server *server, char **argv, int a);
void init_action(t_Player *player);
void start_action(t_Server *server, t_Player *player, int action_time);
void check_action_status(t_Server *server);
void action_update_time(t_Server *server);
char *get_data_from_line(t_Player *player);
int add_data_in_line(t_Player * player, char *order);
void ini_waiting_line(t_Player *player);
void update_player_life(t_Server *server);
void check_player_death(t_Server *server);
void my_add_player(t_Server *server, int fd);
int		my_add_player_id(t_Server *server, int fd);
void my_delete_player(t_Server *server, int id);
void init_case2(t_Map *tmp);
void start_look(t_Server *server, t_Player *tmp, char *data);
void take_food(int id, t_Server *server);

#endif /* !ZAPPY_MAIN_H_ */
