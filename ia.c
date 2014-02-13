/*
** play.c for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Feb  6 13:24:24 2014 chapui_s
** Last update Thu Feb 13 11:47:14 2014 chapui_s
*/

#include <stdlib.h>
#include <unistd.h>
#include "allum.h"

static int	get_xor(t_allum *allum)
{
  t_allum	*tmp;
  unsigned int	xor_tmp;

  xor_tmp = 0;
  tmp = allum->next;
  while (tmp != allum)
  {
    xor_tmp = xor_tmp ^ tmp->nb;
    tmp = tmp->next;
  }
  return (xor_tmp);
}

static int	get_xor_mod(t_allum *allum, unsigned int *line, int tmp_nb)
{
  t_allum	*tmp;
  unsigned int	xor_tmp;
  unsigned int	line_current;

  xor_tmp = 0;
  tmp = allum->next;
  line_current = 1;
  while (tmp != allum)
  {
    if (*line != line_current)
      xor_tmp = xor_tmp ^ tmp->nb;
    else
      xor_tmp = xor_tmp ^ tmp_nb;
    tmp = tmp->next;
    line_current += 1;
  }
  return (xor_tmp);
}

static int	find_xor_zero(t_allum *allum, unsigned int *line)
{
  t_allum	*tmp_allum;
  int		tmp_nb;

  *line = 1;
  tmp_allum = allum->next;
  while (tmp_allum != allum)
  {
    tmp_nb = tmp_allum->nb;
    while (tmp_nb >= 0)
    {
      if ((get_xor_mod(allum, line, tmp_nb)) == 0)
	return (tmp_nb);
      tmp_nb -= 1;
    }
    *line = *line + 1;
    tmp_allum = tmp_allum->next;
  }
  return (tmp_nb);
}

static int	is_one_pile_greater_than_one(t_allum *allum,
					     unsigned int *nb_one,
					     unsigned int *nb_greater)
{
  t_allum	*tmp;

  *nb_one = 0;
  *nb_greater = 0;
  tmp = allum->next;
  while (tmp != allum)
  {
    if (tmp->nb == 1)
      (*nb_one) += 1;
    else if (tmp->nb > 1)
      (*nb_greater) += 1;
    tmp = tmp->next;
  }
  return (*nb_greater);
}

void		ia_turn(t_allum *allum, t_info *info)
{
  unsigned int	line_to_mod;
  unsigned int	allum_to_keep;
  unsigned int	nb_one;
  unsigned int	nb_greater;

  if (info->difficultie == HARD)
  {
    if (get_xor(allum) == 0)
      rm_less_one(allum);
    else if ((is_one_pile_greater_than_one(allum, &nb_one, &nb_greater) > 1)
	     || (info->mode == NORMAL))
    {
      allum_to_keep = find_xor_zero(allum, &line_to_mod);
      rm_nb_allum(allum_to_keep, line_to_mod, allum);
    }
    else
      rm_greater(allum, nb_one);
  }
  else
    rm_less_one(allum);
  reselect(allum);
}
