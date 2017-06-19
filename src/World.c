#include "zappy.h"

t_Map *init_case()
{
	t_Map *tmp;

	tmp = malloc(sizeof(t_Map));
	if (rand() % 3 == 0)
		tmp->deraumere = 1;
	else
		tmp->deraumere = 0;
	if (rand() % 3 == 0)
		tmp->linemate = 1;
	else
		tmp->linemate = 0;
	if (rand() % 3 == 0)
		tmp->mendiane = 1;
	else
		tmp->mendiane = 0;
	if (rand() % 3 == 0)
		tmp->phiras = 1;
	else
		tmp->phiras = 0;
	if (rand() % 3 == 0)
		tmp->sibur = 1;
	else
		tmp->sibur = 0;
	if (rand() % 3 == 0)
		tmp->thystane = 1;
	else
		tmp->thystane = 0;
	tmp->is_occuped = false;
	return(tmp);
}

void basic_init_world(t_World * world)
{
	world->height = -1;
	world->width = -1;
	world->nbr_player = 0;
}

void print_world(t_World *world, int c)
{
	int a;
	int b;

	a = 0;
	while(world->map[a])
	{
		b = 0;
		while(b < c)
		{
			printf("Map position: %d - %d\n", a, b);
			printf("deraumere: %d\n", world->map[a][b]->deraumere);
			printf("linemate: %d\n", world->map[a][b]->linemate);
			printf("mendiane: %d\n", world->map[a][b]->mendiane);
			printf("phiras: %d\n", world->map[a][b]->phiras);
			printf("sibur: %d\n", world->map[a][b]->sibur);
			printf("thystane: %d\n", world->map[a][b]->thystane);
			b += 1;
		}
		a += 1;
	}
}

bool case_occupation(t_World *world, int x, int y)
{
	return(world->map[x][y]->is_occuped);
}

void set_occupation(t_World *world, int x, int y, bool status)
{
	if (world->map[x][y]->is_occuped == true && status == true)
	{
		printf("[ERROR] box already true\n");
		exit(1);
	}
	world->map[y][y]->is_occuped = status;
}

void init_world(t_World * world)
{
	int a;
	int b;

	b = 0;
	if (world->height == -1)
		world->height = 20;
	if (world->width == -1)
		world->width = 20;
	printf("World initialized with height %d and width %d\n", world->height, world->width);
	a = 0;
	world->map = malloc(sizeof(t_Map **) * (world->height * world->width));
	while (a < world->height)
	{
		world->map[a] = malloc(sizeof(t_Map **) * world->height);
		b = 0;
		while (b < world->width)
		{
			world->map[a][b] = init_case();
			b += 1;
		}
		a += 1;
	}
	world->map[a] = NULL;
	if (DEBUG)
		print_world(world, a);
}
