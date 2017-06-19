#ifndef ZAPPY_PLAYER_H_
# define ZAPPY_PLAYER_H_

#include <stdio.h>
#include <stdlib.h>
#include "basic_data.h"

typedef struct	s_Player
{
	t_Position pos;
	struct s_Player *next;
	int fd;
	int id;
	bool is_connected;
}			t_Player;

t_Player *init_player();

#endif /* !ZAPPY_PLAYER_H_ */
