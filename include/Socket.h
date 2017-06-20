/*
** Socket.h for zappy in /home/alaism/dev/tek2/PSU/zappy/include/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:00:10 2017 Martin Alais
** Last update Mon Jun 19 19:24:53 2017 Martin Alais
*/

#ifndef ZAPPY_SOCKET_H_
# define ZAPPY_SOCKET_H_

#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "basic_data.h"

typedef struct	s_Connection
{
	int fd;
	int port;
	char *ip_addr;
	struct protoent	*protocole;
	struct sockaddr_in	s_in;
	struct sockaddr_in	s_in_accept;
	socklen_t		s_in_size_accept;
}			t_Connection;

void init_socket(t_Connection *connection);
void basic_init_socket(t_Connection *connection);
int set_socket_statue(int fd, int blocking);
bool send_message(int fd, char *msg);

#endif /* !ZAPPY_SOCKET_H_ */
