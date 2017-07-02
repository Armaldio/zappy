/*
** mouvement.h for zappy in /home/alaism/dev/tek2/PSU/zappy/include/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 18:59:44 2017 Martin Alais
** Last update Sun Jul  2 17:17:00 2017 martin alais
*/

#ifndef ZAPPY_MOVEMENT_H_
# define ZAPPY_MOVEMENT_H_

#include "Server.h"

void	go_up(t_Server *server, int id, bool send_msg);
void	go_down(t_Server *server, int id, bool send_msg);
void	go_right(t_Server *server, int id, bool send_msg);
void	go_left(t_Server *server, int id, bool send_msg);

#endif /* !ZAPPY_MOVEMENT_H_ */
