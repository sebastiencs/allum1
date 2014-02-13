/*
** play.c for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Feb  6 13:24:24 2014 chapui_s
** Last update Thu Feb 13 13:07:39 2014 chapui_s
*/

#include <stdlib.h>
#include <unistd.h>
#include "allum.h"

t_allum		*manage_nb(t_info *info, t_allum *allum)
{
  int		nb_c;
  int		r_c;
  int		r_all;

  nb_c = 1;
  r_c = 1;
  (info->nb_allum < 2) ? (info->nb_allum = 2) : (0);
  r_all = info->nb_allum;
  while (nb_c <= r_all && ((info->a_mod == 1 && info->r_mod == 0) ?
  			   (1) : (r_c < info->nb_rang)))
  {
    if ((push_back(&allum, ((r_c != info->nb_rang || info->a_mod == 1) ?
    			    (nb_c) : (r_all)))) == -1)
      return (NULL);
    r_all -= ((r_c != info->nb_rang || info->a_mod == 1) ?
	      (nb_c) : (r_all));
    nb_c += 2;
    r_c += 1;
  }
  if (r_all != 0 && insert_rest(allum, r_all) == -1)
    return (NULL);
  if (r_c != info->nb_rang && info->r_mod && add_r(allum, info->nb_rang) == -1)
    return (NULL);
  return (allum);
}

void		rm_nb_allum(unsigned int allum_to_keep,
			    unsigned int line_to_mod,
			    t_allum *allum)
{
  unsigned int	tmp_line;
  t_allum	*tmp;

  tmp_line = 1;
  tmp = allum->next;
  while (tmp_line != line_to_mod)
  {
    tmp = tmp->next;
    tmp_line += 1;
  }
  tmp->nb = allum_to_keep;
}

void		rm_greater(t_allum *allum,
			   unsigned int nb_one)
{
  t_allum	*tmp;
  int		is_rm;

  is_rm = 0;
  tmp = allum->next;
  while (tmp != allum)
  {
    if (tmp->nb > 1)
    {
      if ((nb_one % 2) == 0)
	tmp->nb = 1;
      else
	tmp->nb = 0;
      is_rm = 1;
    }
    tmp = tmp->next;
  }
  if (is_rm == 0)
    rm_less_one(allum);
}

void		reselect(t_allum *allum)
{
  t_allum	*tmp;

  tmp = allum->next;
  while (tmp != allum && tmp->nb == 0)
    tmp = tmp->next;
  tmp->is_select = 1;
  tmp->nb_select = tmp->nb;
  tmp = tmp->next;
  while (tmp != allum)
  {
    tmp->is_select = 0;
    tmp = tmp->next;
  }
}

void		rm_less_one(t_allum *allum)
{
  t_allum	*tmp;

  tmp = allum->next;
  while (tmp->nb == 0 && tmp != allum)
    tmp = tmp->next;
  tmp->nb = tmp->nb - 1;
  if (tmp->nb == 0)
    tmp->is_select = 0;
  while (tmp->nb == 0 && tmp != allum)
    tmp = tmp->next;
  tmp->is_select = 1;
  tmp->nb_select = tmp->nb;
}
