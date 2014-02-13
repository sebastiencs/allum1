/*
** mod_list.c for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Feb  6 14:37:07 2014 chapui_s
** Last update Fri Feb  7 18:48:01 2014 chapui_s
*/

#include "allum.h"

int		insert_rest(t_allum *root, int nb)
{
  t_allum	*new;
  t_allum	*tmp;

  tmp = root->next;
  if ((new = create_list(nb)))
  {
    while (tmp->next->nb <= nb && tmp->next != root)
      tmp = tmp->next;
    new->prec = tmp;
    new->next = tmp->next;
    tmp->next->prec = new;
    tmp->next = new;
    root->nb_elem += 1;
    return (0);
  }
  return (-1);
}

static int	get_nb_rang(t_allum *root)
{
  int		nb;
  t_allum	*tmp;

  nb = 0;
  tmp = root->next;
  while (tmp != root)
  {
    nb += 1;
    tmp = tmp->next;
  }
  return (nb);
}

static int	rm_each_rang(t_allum *root)
{
  t_allum	*tmp;
  int		i;

  i = 0;
  tmp = root->next->next;
  while (tmp != root)
  {
    if (tmp->nb != 1)
    {
      tmp->nb -= 1;
      i = i + 1;
    }
    tmp = tmp->next;
  }
  return (i);
}

int		add_r(t_allum *root, int rang_to_get)
{
  while (get_nb_rang(root) < rang_to_get)
  {
    if ((root->prec->nb) > (root->prec->prec->nb + root->prec->prec->nb))
    {
      if ((insert_rest(root, root->prec->prec->nb)) == -1)
	return (-1);
      root->prec->nb -= root->prec->prec->nb;
    }
    else if ((root->prec->nb) > (root->prec->prec->nb + 2))
    {
      if ((insert_rest(root, root->prec->nb
		       - (root->prec->prec->nb + 2))) == -1)
	return (-1);
      root->prec->nb -= (root->prec->prec->nb + 2);
    }
    else
    {
      if ((insert_rest(root, rm_each_rang(root))) == -1)
	return (-1);
    }
  }
  return (0);
}
