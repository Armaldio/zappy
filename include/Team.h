/*
** Team.h for zappy in /home/hammouche/Documents/PSU_2016/zappy/include/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Mon Jun 19 15:32:56 2017 hamza hammouche
** Last update Mon Jun 19 17:05:01 2017 hamza hammouche
*/

#ifndef TEAM_H_
# define TEAM_H_

#include "Server.h"

t_team	*create_team(char *name);
t_team	*add_team(t_team *head, char *name);

#endif /* end of include guard: TEAM_H_ */
