/*
** parser.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/graphic/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 15:50:27 2017 Martin Alais
** Last update Thu Jun 22 17:43:34 2017 hamza hammouche
*/

#include "zappy.h"
#include "Graphic.h"

bool graphic_parser(int id, t_Server *server, char *data)
{
	char	*mcommand[] = {"GRAPHIC", "msz", NULL};
	void	*mfunction_ptr[] = {commande_graphic, NULL};
	void	(*fct_ptr)(t_Player *, t_Server *, char *);
	t_Player *tmp;
	int		a;

	a = 0;
	tmp = get_Player(id, server->list_player);
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
	return (false);
}
