/*
** Incantation.h for zappy in /home/alaism/dev/tek2/PSU/zappy/include/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:00:49 2017 Martin Alais
** Last update Wed Jun 21 14:43:31 2017 Martin Alais
*/

#ifndef ZAPPY_INCANTATION_H_
# define ZAPPY_INCANTATION_H_

#include "zappy.h"

void incan_1(t_Server *server, t_Player *player);
void incan_2(t_Server *server, t_Player *player);
void incan_3(t_Server *server, t_Player *player);
void incan_4(t_Server *server, t_Player *player);
void incan_5(t_Server *server, t_Player *player);

int check_nbr_at_level(t_Server *server, int level);

bool	is_ready_to_up_2(t_Player *tmp, t_Player *player);
bool	is_ready_to_up_3(t_Player *tmp, t_Player *player);

void level_up_2(t_Player *player);
void level_up_3(t_Player *player);

#endif /* !ZAPPY_INCANTATION_H_ */
