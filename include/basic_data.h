/*
** basic_data.h for zappy in /home/alaism/dev/tek2/PSU/zappy/include/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:00:53 2017 Martin Alais
** Last update Thu Jun 29 10:53:19 2017 hamza hammouche
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
double my_safe_div(double nbr1, double nbr2);

#endif /* !ZAPPY_BASIC_H_ */
