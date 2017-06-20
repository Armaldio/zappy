/*
** Team_gestion.c for zappy in /home/hammouche/Documents/PSU_2016/zappy/src/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Mon Jun 19 16:04:19 2017 hamza hammouche
** Last update Tue Jun 20 13:44:32 2017 hamza hammouche
*/

#include "Team.h"

t_team *get_team(t_team *head, char *name, int id)
{
  t_team *tmp;

  tmp = head;
  if (name != NULL && name[strlen(name) - 1] == '\n')
    name[strlen(name) - 1] = '\0';
  while (tmp) {
    if ((name != NULL && strcmp(tmp->name, name) == 0) || id == tmp->id)
			return (tmp);
    tmp = tmp->next;
  }
  return (NULL);
}

t_team *create_team(char *name)
{
  t_team *new;

  if ((new = malloc(sizeof(t_team))) == NULL)
    {
      write(2, "[Error] Create Team, malloc fail\n", 32);
      exit(1);
    }
  new->name = strdup(name);
  new->id = 1;
  new->next = NULL;
  return (new);
}

t_team *add_team(t_team *head, char *name)
{
  t_team *new;
  t_team *tmp;

  if (head == NULL)
    return (create_team(name));
  if ((new = malloc(sizeof(t_team))) == NULL)
    {
      write(2, "[Error] Add Team, malloc fail\n", 30);
      exit(1);
    }
  new->name = strdup(name);
  tmp = head;
  while (tmp->next)
    tmp = tmp->next;
  new->id = tmp->id + 1;
  tmp->next = new;
  return (head);
}

int	parser_team(t_Server *serv, char **argv, int a)
{
  t_team *head;
  int				i;

  i = 0;
  head = NULL;
  a++;
  while (argv[a] && argv[a][0] != '-')
    {
      head = add_team(head, argv[a]);
      a++;
      i++;
    }
  serv->list_teams = head;
  return (i);
}
