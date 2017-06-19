#ifndef ZAPPY_PLAYER_H_
# define ZAPPY_PLAYER_H_

#include <stdio.h>
#include <stdlib.h>
#include "basic_data.h"

enum direction {UP, DOWN, RIGHT, LEFT};

typedef struct	s_Player
{
	t_Position pos;
	struct s_Player *next;
	int fd;
	int id;
	bool is_connected;
	enum direction gaze;
}			t_Player;

t_Player *init_player();

#endif /* !ZAPPY_PLAYER_H_ */
