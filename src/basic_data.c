/*
** basic_data.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:23:23 2017 Martin Alais
** Last update Fri Jun 23 14:10:23 2017 Martin Alais
*/

#include "basic_data.h"
#include "zappy.h"

void print(int fd, char *str)
{
	if (write(fd, str, strlen(str)) == -1)
		write(2, "Write Error\n", 12);
}

void *my_malloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		print(2, "Malloc error\n");
		exit(1);
	}
	return (ptr);
}

int my_safe_div(int nbr1, int nbr2)
{
	if (nbr2 == 0)
		return (nbr1);
	return(nbr1 / nbr2);
}
