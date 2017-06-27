/*
** World.h for zappy in /home/alaism/dev/tek2/PSU/zappy/include/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 18:59:02 2017 Martin Alais
** Last update Tue Jun 27 13:31:05 2017 loic1.doyen@epitech.eu
*/

#ifndef ZAPPY_WORLD_H_
# define ZAPPY_WORLD_H_

typedef struct	s_Map
{
	int food;
	int pos_x;
	int pos_y;
	int linemate;
	int deraumere;
	int sibur;
	int mendiane;
	int phiras;
	int thystane;
}	t_Map;

typedef union u_Mapu {
  int tab[9];
    struct {
	    int food;
            int pos_x;
            int pos_y;
            int linemate;
            int deraumere;
            int sibur;
            int mendiane;
            int phiras;
            int thystane;
    } data;
} t_Mapu;

typedef struct	s_World
{
	int height;
	int width;
	int nbr_player;
	t_Map ***map;
}	t_World;

void basic_init_world(t_World * world);
void init_world(t_World * world);
void print_world(t_World *world);

#endif /* !ZAPPY_WORLD_H_ */
