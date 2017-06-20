/*
** commande.c for  in /home/macdoy/Rendu/zappy/src/
**
** Made by loic1.doyen@epitech.eu
** Login   <loic1.doyen@epitech.eu@epitech.eu>
**
** Started on  Tue Jun 20 09:44:32 2017 loic1.doyen@epitech.eu
** Last update Tue Jun 20 14:01:39 2017 Martin Alais
*/

#include "zappy.h"
#include "Incantation.h"

void command_not_found(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	send_message(tmp->fd, "KO\n");
}

void exit_client(int id, t_Server *server, char *data)
{
	t_Player *tmp;

	(void) data;
	printf("close client\n");
	tmp = server->list_player;
	while (tmp->next && tmp->id != id)
		tmp = tmp->next;
	tmp->is_connected = false;
	close(tmp->fd);
}

int parser_commande(int id, t_Server *server, char *data)
{
	char	*mcommand[] = {"Forward", "Right", "Left",
	"Incantation", "Take", "Exit", NULL};
	void	*mfunction_ptr[] = {commande_forward, commande_right,
		commande_left, commande_incantation, command_take, exit_client, NULL};
	void	(*fct_ptr)(int, t_Server *, char *);
	int		a;

	if (data == NULL)
		return (0);
	a = 0;
	while (mcommand[a])
	{
		if (strncmp(mcommand[a], data, strlen(mcommand[a])) == 0)
		{
			fct_ptr = mfunction_ptr[a];
			fct_ptr(id, server, data);
			return (0);
		}
		a += 1;
	}
	command_not_found(id, server);
	return (0);
}
