/*
** mouli.c for mouli in /home/alaism/dev/tek2/PSU/PSU_2016_myftp/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Tue May  9 17:32:18 2017 Martin Alais
** Last update Thu Jun 15 17:05:39 2017 Martin Alais
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int print(int fd, char *str)
{
	if (write(fd, str, strlen(str)) == -1)
	{
		fprintf(stderr, "Can net write in fd\n");
		exit(1);
	}
	return(0);
}

int main(int ac, char **argv)
{
	struct protoent *pe;
	int fd;
	struct sockaddr_in s_in;
	int port;
	char *ip;
	char *data;

	data = malloc(sizeof(char) * 1000);
	if (ac != 3)
	{
		fprintf(stderr, "./mouli ip port\n");
		exit(1);
	}
	ip = argv[1];
	port = atoi(argv[2]);
	pe = getprotobyname("TCP");
	if (!pe)
	{
		fprintf(stderr, "ERROR in getprotobyname\n");
		exit(1);
	}
	fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (fd == -1)
	{
		fprintf(stderr, "Can not initialize socket\n");
		exit(1);
	}
	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(port);
	s_in.sin_addr.s_addr = inet_addr(ip);
	if (connect(fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
	{
		if (close(fd) == -1)
		{
			fprintf(stderr, "Can not connect to socket and can not close socket connection\n");
			exit(1);
		}
		fprintf(stderr, "Can not connect to sokcet\n");
		exit(1);
	}
	memset(data, '\0', 1000);
	struct timeval tv;
	fd_set rfds;
	int a;
	while(strncmp(data, "exit", 4) != 0)
	{
		FD_ZERO(&rfds);
		FD_SET(1, &rfds);
		tv.tv_sec = 0;
		tv.tv_usec = 300;
		a = select(1 + 1, &rfds, NULL, NULL, &tv);
		if (a != 0)
		{
			print(2, "data read from stdin\n");
			read(1, data, 1000);
			send(fd, data, strlen(data), MSG_DONTWAIT | MSG_NOSIGNAL);
			print(2, "data send to server\n");
			memset(data, '\0', 1000);
		}
		FD_ZERO(&rfds);
		FD_SET(fd, &rfds);
		tv.tv_sec = 0;
		tv.tv_usec = 300;
		a = select(fd + 1, &rfds, NULL, NULL, &tv);
		if (a != 0)
		{
			print(2, "data read from oserver\n");
			recv(fd, data, 1000, MSG_DONTWAIT);
			write(1, data, strlen(data));
			write(1, "\n", 1);
			memset(data, '\0', 1000);
		}
	}
}
