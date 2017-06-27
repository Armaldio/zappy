/*
** basic_data.h for zappy in /home/alaism/dev/tek2/PSU/zappy/include/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:00:53 2017 Martin Alais
** Last update Fri Jun 23 14:10:30 2017 Martin Alais
*/

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
int my_safe_div(int nbr1, int nbr2);

#endif /* !ZAPPY_BASIC_H_ */
