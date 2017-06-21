/*
** Player.h for zappy in /home/alaism/dev/tek2/PSU/zappy/include/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:00:44 2017 Martin Alais
** Last update Tue Jun 20 15:39:08 2017 Martin Alais
*/

#ifndef ZAPPY_PLAYER_H_
# define ZAPPY_PLAYER_H_

#include <stdio.h>
#include <stdlib.h>
#include "basic_data.h"

enum direction {UP, DOWN, RIGHT, LEFT};

typedef struct	s_waiting_line
{
	char **line;
	int nbr_ordre;
}			t_waiting_line;

typedef struct	s_action
{
	int start_time;
	int end_time;
	bool is_working;
	bool is_leveling;
}			t_action;

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
	int death_time;
	int life_time;
	int level;
	int teamId;
	struct s_Player *next;
	t_Inventaire *inventaire;
	t_action *action;
	t_waiting_line *waiting_line;
	int fd;
	int id;
	bool is_connected;
  bool waitingTeam;
  bool is_dead;
	enum direction gaze;
}			t_Player;

int				get_Player_size(t_Player *head);
t_Player *get_Player(int id, t_Player *head);
t_Player *init_player();

#endif /* !ZAPPY_PLAYER_H_ */
