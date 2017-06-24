/*
** Player.h for zappy in /home/alaism/dev/tek2/PSU/zappy/include/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:00:44 2017 Martin Alais
** Last update Sat Jun 24 12:45:43 2017 Martin Alais
*/

#ifndef ZAPPY_PLAYER_H_
# define ZAPPY_PLAYER_H_

#include <stdio.h>
#include <stdlib.h>
#include "basic_data.h"

enum direction {UP, RIGHT, DOWN, LEFT};

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
	char data_to_send[4096];
}			t_action;

typedef struct	s_Inventaire
{
	int food;
	int linemate;
	int deraumere;
	int sibur;
	int mendiane;
	int phiras;
	int thystane;
}			t_Inventaire;

typedef struct		s_Player
{
  t_Position		pos;
  int				death_time;
  int				life_time;
  int				level;
  int				teamId;
  bool	isGraphic;
  struct s_Player	*next;
  t_Inventaire		*inventaire;
  t_action			*action;
  t_waiting_line	*waiting_line;
  int				fd;
  int				id;
  int 				id_eggs;
  int				father_id;
  bool				is_connected;
  bool				waitingTeam;
  bool				is_dead;
  enum direction	gaze;
  bool				controlled;
  bool				isEgg;
}					t_Player;

typedef struct	s_undefined
{
	int fd;
	int id;
	struct s_undefined *next;
}			t_undefined;

typedef struct	s_graphic
{
	int fd;
	int id;
	struct s_graphic *next;
}			t_graphic;

int				get_Player_size(t_Player *head);
t_Player		*get_Player(int id, t_Player *head);
t_Player		*init_player();
t_Player		*get_First_Player_Available(t_Player *head);

t_Player	*get_Egg(int id, t_Player *head);
int	get_New_EggID(t_Player *head);

#endif /* !ZAPPY_PLAYER_H_ */
