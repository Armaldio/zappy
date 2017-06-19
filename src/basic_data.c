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
	return(ptr);
}
