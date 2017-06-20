/*
** mouvement.h for zappy in /home/alaism/dev/tek2/PSU/zappy/include/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 18:59:44 2017 Martin Alais
** Last update Mon Jun 19 19:14:35 2017 Martin Alais
*/

#ifndef ZAPPY_MOVEMENT_H_
# define ZAPPY_MOVEMENT_H_

#include "Server.h"

int go_up(t_Server *server, int id);
int go_down(t_Server *server, int id);
int go_right(t_Server *server, int id);
int go_left(t_Server *server, int id);
void go_up2(t_Server *server, t_Player *tmp);
void go_down2(t_Server *server, t_Player *tmp);
void go_right2(t_Server *server, t_Player *tmp);
void go_left2(t_Server *server, t_Player *tmp);
#endif /* !ZAPPY_MOVEMENT_H_ */
