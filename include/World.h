/*
** World.h for zappy in /home/alaism/dev/tek2/PSU/zappy/include/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 18:59:02 2017 Martin Alais
** Last update Tue Jun 20 17:40:12 2017 Martin Alais
*/

#ifndef ZAPPY_WORLD_H_
# define ZAPPY_WORLD_H_

typedef struct	s_Map
{
	bool is_occuped;
	int food;
	int pos_x;
	int pos_y;
	int linemate;
	int deraumere;
	int sibur;
	int mendiane;
	int phiras;
	int thystane;
}			t_Map;

typedef struct	s_World
{
	int height;
	int width;
	int nbr_player;
	t_Map ***map;
}			t_World;

void basic_init_world(t_World * world);
void init_world(t_World * world);
bool case_occupation(t_World *world, int x, int y);
void set_occupation(t_World *world, int x, int y, bool status);
void print_world(t_World *world);

#endif /* !ZAPPY_WORLD_H_ */
