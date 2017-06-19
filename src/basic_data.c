/*
** basic_data.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:23:23 2017 Martin Alais
** Last update Mon Jun 19 19:23:28 2017 Martin Alais
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
