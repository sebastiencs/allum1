/*
** disp.c for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Feb  6 16:12:24 2014 chapui_s
** Last update Thu Feb 13 10:53:55 2014 chapui_s
*/

#include <stdlib.h>
#include <unistd.h>
#include "allum.h"

static int	get_nb_max(t_allum *allum)
{
  t_allum	*tmp;
  int		max;

  tmp = allum->next;
  max = tmp->nb;
  while (tmp != allum)
  {
    if (tmp->nb > max)
      max = tmp->nb;
    tmp = tmp->next;
  }
  return (max);
}

void		disp_allum(t_allum *allum)
{
  static int	nb_max;
  t_allum	*tmp;
  int		i;

  (nb_max == 0) ? (nb_max = get_nb_max(allum)) : (0);
  tmp = allum->next;
  my_tputs(tgetstr("cl", NULL));
  my_putchar('\n');
  while (tmp != allum)
  {
    i = 0;
    my_putchar(' ');
    while (i++ < nb_max - tmp->nb)
      write(1, " ", 1);
    i = 0;
    while (i < tmp->nb)
    {
      (i == (tmp->nb - tmp->nb_select) && tmp->is_select == 1) ?
	(my_tputs(tgetstr("so", NULL))) : (0);
      my_putstr((++i < tmp->nb) ? ("| ") : ("|"));
    }
    (tmp->is_select == 1) ? (my_tputs(tgetstr("se", NULL))) : (0);
    my_putstr("\n\n");
    tmp = tmp->next;
  }
}
