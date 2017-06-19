#ifndef ZAPPY_MOVEMENT_H_
# define ZAPPY_MOVEMENT_H_

#include "Server.h"

void go_up(t_Server *server, int id);
void go_down(t_Server *server, int id);
void go_right(t_Server *server, int id);
void go_left(t_Server *server, int id);
void go_up2(t_Server *server, t_Player *tmp);
void go_down2(t_Server *server, t_Player *tmp);
void go_right2(t_Server *server, t_Player *tmp);
void go_left2(t_Server *server, t_Player *tmp);
#endif /* !ZAPPY_MOVEMENT_H_ */
