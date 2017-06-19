/*
** Player.h for zappy in /home/alaism/dev/tek2/PSU/zappy/include/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:00:44 2017 Martin Alais
** Last update Mon Jun 19 19:00:47 2017 Martin Alais
*/

#ifndef ZAPPY_PLAYER_H_
# define ZAPPY_PLAYER_H_

#include <stdio.h>
#include <stdlib.h>
#include "basic_data.h"

enum direction {UP, DOWN, RIGHT, LEFT};

typedef struct	s_Inventaire
{
	int linemate;
	int deraumere;
	int sibur;
	int mendiane;
	int phiras;
	int thystane;
}			t_Inventaire;

typedef struct	s_Player
{
	t_Position pos;
	int level;
	struct s_Player *next;
	t_Inventaire *inventaire;
	int fd;
	int id;
	bool is_connected;
	enum direction gaze;
}			t_Player;

t_Player *init_player();

#endif /* !ZAPPY_PLAYER_H_ */
