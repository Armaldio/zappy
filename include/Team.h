/*
** Team.h for zappy in /home/hammouche/Documents/PSU_2016/zappy/include/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Mon Jun 19 15:32:56 2017 hamza hammouche
** Last update Tue Jun 20 10:39:32 2017 hamza hammouche
*/

#ifndef TEAM_H_
# define TEAM_H_

#include "Server.h"

t_team	*create_team(char *name);
t_team	*add_team(t_team *head, char *name);
t_team	*get_team(t_team *head, char *name, int id);

#endif /* end of include guard: TEAM_H_ */
