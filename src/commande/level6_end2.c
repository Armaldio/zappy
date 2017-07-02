/*
** level6_end2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Wed Jun 28 21:34:31 2017 Martin Alais
** Last update Sun Jul  2 15:07:03 2017 martin alais
*/

#include "zappy.h"

int	*build_tab_6()
{
  int	*tab;

  tab = malloc(sizeof(int) * 7);
  tab[0] = 0;
  tab[1] = 1;
  tab[2] = 2;
  tab[3] = 3;
  tab[4] = 0;
  tab[5] = 1;
  tab[6] = 0;
  return (tab);
}
