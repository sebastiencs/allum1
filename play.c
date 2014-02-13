/*
** play.c for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Feb  6 13:24:24 2014 chapui_s
** Last update Thu Feb 13 11:09:00 2014 chapui_s
*/

#include <stdlib.h>
#include <unistd.h>
#include "allum.h"

void		print_winner(int nb_one, int who, t_info *info)
{
  if (nb_one == 1)
  {
    if (who == IA_TURN && info->mode == MISERE)
      my_putstr("\033[32m ==> YOU WIN <== \033[0m\n\n");
    else
      my_putstr("\033[31m ==> YOU LOSE <== \033[0m\n\n");
  }
  else if (nb_one == 0)
  {
    if (who == IA_TURN && info->mode == NORMAL)
      my_putstr("\033[32m ==> YOU WIN <== \033[0m\n\n");
    else
      my_putstr("\033[31m ==> YOU LOSE <== \033[0m\n\n");
  }
}

int		is_continue(t_allum *allum, int who, t_info *info)
{
  t_allum	*tmp;
  unsigned int	nb_one;

  tmp = allum->next;
  nb_one = 0;
  while (tmp != allum)
  {
    if (tmp->nb == 1)
      nb_one += 1;
    else if (tmp->nb > 1)
      nb_one += 10;
    tmp = tmp->next;
  }
  if (nb_one == 0 || nb_one == 1)
  {
    disp_allum(allum);
    print_winner(nb_one, who, info);
    return (0);
  }
  return (1);
}

int		play(t_allum *allum, t_func *list_func, t_info *info)
{
  char		buffer[BUF_SIZE];

  while (is_continue(allum, PLAYER_TURN, info) == 1)
  {
    disp_allum(allum);
    if ((cmd(buffer, list_func, allum, info)) <= 0)
      return (0);
  }
  return (0);
}
