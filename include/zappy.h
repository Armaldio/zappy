#ifndef ZAPPY_MAIN_H_
# define ZAPPY_MAIN_H_

#include "Server.h"
#include "mouvement.h"

void parser_data(t_Server *server, char **argv);
void parser_commande(int id, t_Server *server, char *data);
#endif /* !ZAPPY_MAIN_H_ */
