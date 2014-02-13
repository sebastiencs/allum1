/*
** move.c for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Feb  6 17:43:23 2014 chapui_s
** Last update Sat Feb  8 20:56:24 2014 chapui_s
*/

#include "allum.h"

void		move_up(t_allum *allum)
{
  t_allum	*tmp;

  tmp = allum->next;
  while (tmp->is_select == 0 && tmp != allum)
    tmp = tmp->next;
  tmp->is_select = 0;
  tmp = tmp->prec;
  while (tmp->nb == 0 || tmp == allum)
    tmp = tmp->prec;
  tmp->is_select = 1;
  tmp->nb_select = tmp->nb;
}

void		move_down(t_allum *allum)
{
  t_allum	*tmp;

  tmp = allum->next;
  while (tmp->is_select == 0)
    tmp = tmp->next;
  tmp->is_select = 0;
  tmp = tmp->next;
  while (tmp->nb == 0 || tmp == allum)
    tmp = tmp->next;
  tmp->is_select = 1;
  tmp->nb_select = tmp->nb;
}

void		less_matches(t_allum *allum)
{
  t_allum	*tmp;

  tmp = allum->next;
  while (tmp->is_select == 0)
    tmp = tmp->next;
  if (tmp->nb_select > 1)
    tmp->nb_select -= 1;
}

void		more_matches(t_allum *allum)
{
  t_allum	*tmp;

  tmp = allum->next;
  while (tmp->is_select == 0)
    tmp = tmp->next;
  if (tmp->nb_select < tmp->nb)
    tmp->nb_select += 1;
}

void		rm_matches(t_allum *allum)
{
  t_allum	*tmp;
  int		is_loop;

  tmp = allum->next;
  is_loop = 0;
  while (tmp->is_select == 0)
    tmp = tmp->next;
  tmp->nb -= tmp->nb_select;
  if (tmp->nb < 0)
    tmp->nb = 0;
  tmp->nb_select = tmp->nb;
  if (tmp->nb == 0)
  {
    tmp->is_select = 0;
    tmp = tmp->next;
    while ((tmp->nb == 0 || tmp == allum) && is_loop != 2)
    {
      (tmp == allum) ? (is_loop += 1) : (0);
      tmp = tmp->next;
    }
    tmp->is_select = 1;
    tmp->nb_select = tmp->nb;
  }
}
