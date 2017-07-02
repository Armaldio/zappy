/*
** generic_level.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Tue Jun 27 13:01:36 2017 Martin Alais
** Last update Sun Jul  2 14:48:32 2017 martin alais
*/

#include "zappy.h"

int	*build_tab(t_Server *server, t_Player *player)
{
  int	*tab;

  tab = malloc(sizeof(int) * 7);
  tab[0] = server->world->map[player->pos.x][player->pos.y]->food;
  tab[1] = server->world->map[player->pos.x][player->pos.y]->linemate;
  tab[2] = server->world->map[player->pos.x][player->pos.y]->deraumere;
  tab[3] = server->world->map[player->pos.x][player->pos.y]->sibur;
  tab[4] = server->world->map[player->pos.x][player->pos.y]->mendiane;
  tab[5] = server->world->map[player->pos.x][player->pos.y]->phiras;
  tab[6] = server->world->map[player->pos.x][player->pos.y]->thystane;
  return (tab);
}

bool	compare_tab(int *tab, int *tab2)
{
  int	nbr;

  nbr = 1;
  while (nbr < 7)
    {
      if (tab[nbr] != tab2[nbr])
	return (false);
      nbr += 1;
    }
  return (true);
}

int		nbr_case(t_Server *server, t_Player *player)
{
  t_Player	*tmp;
  int		nbr;

  nbr = 0;
  tmp = server->list_player;
  while (tmp)
    {
      if (tmp->pos.x == player->pos.x &&  tmp->pos.y == player->pos.y)
	nbr += 1;
      tmp = tmp->next;
    }
  printf("nbr return: %d\n", nbr);
  return (nbr);
}

int		nbr_case_rdy(t_Server *server, t_Player *player)
{
  t_Player	*tmp;
  int		nbr;

  nbr = 0;
  tmp = server->list_player;
  while (tmp)
    {
      if (tmp->pos.x == player->pos.x &&  tmp->pos.y == player->pos.y)
	nbr += 1;
      tmp = tmp->next;
    }
  return (nbr);
}

void	send_to_level_up(t_Player *player, t_Server *server)
{
  void	*mfunction_ptr[] = {end_level1, end_level2, end_level3,
			    end_level4, end_level5, end_level6, end_level7, NULL};
  int	(*fct_ptr)(t_Server *, t_Player *);

  fct_ptr = mfunction_ptr[player->level - 1];
  fct_ptr(server, player);
  send_message_bct_pos(server, server->list_graphic, player->pos.x,
		       player->pos.y);
}
