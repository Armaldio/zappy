#ifndef ZAPPY_BASIC_H_
# define ZAPPY_BASIC_H_

#include <stdlib.h>

typedef enum {false, true} bool;

typedef struct	s_Position
{
	int x;
	int y;
}			t_Position;


void print(int fd, char *str);
void *my_malloc(size_t size);

#endif /* !ZAPPY_BASIC_H_ */
