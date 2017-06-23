/*
** Graphic.h for zappy in /home/alaism/dev/tek2/PSU/zappy/include/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 15:51:04 2017 Martin Alais
** Last update Fri Jun 23 10:52:58 2017 Martin Alais
*/

#ifndef ZAPPY_GRAPHIC_H_
# define ZAPPY_GRAPHIC_H_

#include "zappy.h"

void commande_graphic(t_Player *player, t_Server *server, char *data);
void commande_msz(t_Player *player, t_Server *server, char *data);
void commande_sgt(t_Player *player, t_Server *server, char *data);
void commande_bct2(t_Server *server, int x, int y, t_Player *player);
void commande_tna(t_Player *player, t_Server *server, char *data);
void commande_pnw(t_Player *player, t_Server *server, char *dataaze);
void commande_btc(t_Player *player, t_Server *server, char *data);
void commande_mct(t_Player *player, t_Server *server, char *data);
void commande_ppo(t_Player *player, t_Server *server, char *data2);
void commande_plv(t_Player *player, t_Server *server, char *data2);
void commande_pin(t_Player *player, t_Server *server, char *data2);
void commande_sst(t_Player *player, t_Server *server, char *data2);

#endif /* !ZAPPY_GRAPHIC_H_ */
