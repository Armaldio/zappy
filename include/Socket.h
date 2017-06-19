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
void set_socket_statue(int fd, int blocking);


#endif /* !ZAPPY_SOCKET_H_ */
