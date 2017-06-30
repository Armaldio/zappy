/*
** parser.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/graphic/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 15:50:27 2017 Martin Alais
** Last update Fri Jun 30 16:31:07 2017 Martin Alais
*/

#include "zappy.h"
#include "Graphic.h"

t_graphic *get_graphic_user(int id, t_Server *server)
{
	t_graphic *tmp;

	tmp = server->list_graphic;
	while (tmp)
	{
		if (tmp->id == id)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

bool graphic_parser(int id, t_Server *server, char *data)
{
	char	*mcommand[] = {"msz", "tna", "sgt", "bct",
	"mct", "ppo", "plv", "pin", "sst", NULL};
	void	*mfunction_ptr[] = {commande_msz, commande_tna,
		commande_sgt, commande_btc, commande_mct, commande_ppo,
		commande_plv, commande_pin, commande_sst, NULL};
	void	(*fct_ptr)(t_graphic *, t_Server *, char *);
	t_graphic *tmp;
	int		a;

	a = 0;
	tmp = get_graphic_user(id, server);
	while (mcommand[a])
	{
		if (strncmp(mcommand[a], data, get_size_commmande(data)) == 0)
		{
			fct_ptr = mfunction_ptr[a];
			fct_ptr(tmp, server, data);
			return (true);
		}
		a += 1;
	}
	send_message_graphic(tmp, "suc\n");
	return (false);
}
