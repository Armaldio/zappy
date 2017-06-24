/*
** Event.h for zappy in /home/alaism/dev/tek2/PSU/zappy/include/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Sat Jun 24 11:32:03 2017 Martin Alais
** Last update Sat Jun 24 16:10:03 2017 Martin Alais
*/

#ifndef ZAPPY_EVENT_H_
# define ZAPPY_EVENT_H_

#include "zappy.h"
#include "Graphic.h"

void send_all_player(t_Server *server, t_graphic *graphic);
void event_new_player(t_Server *server, t_Player *player);
void event_conection_for_eggs(t_Server *server, t_Player *player);
void event_ppo(t_Server *server, t_Player *player);
void event_take(t_Server *server, t_Player *player, int id_ressource);
void event_drop(t_Server *server, t_Player *player, int id_ressource);
void event_eject(t_Server *server, t_Player *player);
void event_eject2(t_Server *server, t_Player *player);

#endif /* !ZAPPY_EVENT_H_ */
