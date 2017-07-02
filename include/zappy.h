/*
** zappy.h for zappy in /home/alaism/dev/tek2/PSU/zappy/include/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:00:24 2017 Martin Alais
** Last update Sun Jul  2 19:05:06 2017 Martin Alais
*/

#ifndef ZAPPY_MAIN_H_
# define ZAPPY_MAIN_H_

#include "Team.h"
#include "mouvement.h"
#include <sys/time.h>
#include <poll.h>

# define DEBUG 0

typedef struct    s_point {
  int x;
  int y;
}            t_point;

void parser_data(t_Server *server, int ac, char **argv);
int	parser_team(t_Server *serv, char **argv, int a);
void	event_endI(t_Server *server, t_Player *player);
int	get_poll_timeout(t_Server *server);
int parser_commande(int id, t_Server *server, char *data);
void send_message_death(t_graphic *, int);
void send_message_pie(t_graphic *, t_Player *p);
void	send_message_bct_pos(t_Server *serv, t_graphic *head, int x, int y);
void	send_message_position(t_graphic *, char *msg);
void commande_forward(int id, t_Server *server, char *data);
void commande_right(int id, t_Server *server, char *data);
void commande_left(int id, t_Server *server, char *data);
void commande_incantation(int id, t_Server *server, char *data);
void	command_fork(int id, t_Server *server, char *data);
void	command_hatch(int id, t_Server *server, char *data);
void	command_bloom(int id, t_Server *server, char *data);
int command_take(int id, t_Server *server, char *data);
int command_look(int id, t_Server *server, char *data);
int command_broadcast(int id, t_Server *server, char *data);
int parser_nbMax(t_Server *server, char **argv, int a);
int parser_port(t_Server *server, char **argv, int a);
int parser_width(t_Server *server, char **argv, int a);
int parser_height(t_Server *server, char **argv, int a);
int parser_freq(t_Server *server, char **argv, int a);
void init_action(t_Player *player);
void start_action(t_Server *server, t_Player *player, int action_time);
void check_action_status(t_Server *server);
void action_update_time(t_Server *server, double elapsed_time);
char *get_data_from_line(t_Player *player);
int add_data_in_line(t_Player * player, char *order);
void ini_waiting_line(t_Player *player);
void update_player_life(t_Server *server, double elapsed_time);
void check_player_death(t_Server *server);
void my_add_player(t_Server *server, int fd);
void	event_endI(t_Server *server, t_Player *player);
void my_delete_player(t_Server *server, int id);
void init_case2(t_Map *tmp);
void start_look(t_Server *server, t_Player *tmp, char *data);
void take_food(int id, t_Server *server);
void check_player_leveling(t_Server *server);
int command_set(int id, t_Server *server, char *data);
void exit_client(int id, t_Server *server, char *data);
void command_eject(int id, t_Server *server, char *data);
void command_inventory(int id, t_Server *server, char *data);
bool graphic_parser(int id, t_Server *server, char *data);
int get_size_commmande(char *str);
void stok_answer(t_Player *player, char *answer);
void send_answer(t_Player *player);
void add_graphic(int fd, t_Server *server);
void add_undefined(int fd, t_Server *server);
void delete_undefine(t_Server *server, int id);
void delete_graphic(t_Server *server, int id);
void undefined_to_player(t_Server *server, t_undefined *undefine, t_team *team);
void undefined_to_graphic(t_Server *server, t_undefined *undefine);
int get_eggs_id(t_Server *server);
void my_init_eggs(t_Player *, int id, t_Server *server, int father_id);
int my_add_eggs(t_Server *server, t_Player *player);
t_Player *get_eggs(int id, t_Player *head);
bool check_data_undefine(int, char *, t_Server *server);
void add_to_line(t_Player *tmp, char *data_recv, t_Server *server);
void my_poll(t_Server *server);
int poll_nbr_fd2(t_Server *server);
void complete_struct2(t_Server *server, void *poll_fd, int nbr);
bool send_for_graphic(t_Server *server, int fd, char *data_recv);
bool send_for_undefine(t_Server *server, int fd, char *data_recv);
void end_level1(t_Server *server, t_Player *player);
void end_level2(t_Server *server, t_Player *player);
void send_to_level_up(t_Player *player, t_Server *server);
int *build_tab(t_Server *server, t_Player *player);
bool compare_tab(int *, int *tab2);
int *build_tab_3();
int *build_tab_4();
int *build_tab_5();
int *build_tab_2();
int *build_tab_6();
int *build_tab_7();
int nbr_case(t_Server *server, t_Player *player);
int nbr_case_rdy(t_Server *server, t_Player *player);
int check_nbr_at_level(t_Server *server, t_Player *player, int level);
void end_level3(t_Server *server, t_Player *player);
void end_level4(t_Server *server, t_Player *player);
void end_level5(t_Server *server, t_Player *player);
void end_level6(t_Server *server, t_Player *player);
void end_level7(t_Server *server, t_Player *player);
void complete_struct6(t_Player **tmp2, t_Player *player, bool);
bool error_level_6(t_Player *player, t_Server *server);
void invalide_level6(t_Server *server, t_Player *player);
void reset_level6(t_Player *player);
void set_incan2(t_Player *player, t_Player *tmp);
t_Player **get_list_level_4(t_Server *server, t_Player *player);
bool error_level_4(t_Player *player, t_Server *server);
void clean_player4(t_Player *player);
bool incan_4bis(t_Server *server, t_Player *player);
void complete_struct(t_Server *server, struct pollfd *poll_fd);
int poll_nbr_fd(t_Server *server);
int get_nbr_del(char *str, char del);
void free_tab(char **tab);
void str_tab_2(char **res, char *str, char del);
void add_rand_food(t_Server *server);
void	bonsoir(t_Player *tmp, t_point res, char **message);
int	bonjour(t_Player *tmp, t_point res, char **message);
void	ouais_fini(int id, char *message, char *data, t_Player **tmp);
void player_disconnected(t_Player *player, t_Server *server);
void complete_read(t_Player *tmp3, char *data_recv);
void complete_read_graphic(t_graphic *tmp3, char *data_recv, t_Server *server);
void complete_read_undefine(t_undefined *player, char *data_recv,
	t_Server *server);
bool send_message_undefine(t_undefined *player, char *msg);
bool send_message_graphic(t_graphic *player, char *msg);
bool check_valide_commande(t_Player *player, int size, char *data);

#endif /* !ZAPPY_MAIN_H_ */
