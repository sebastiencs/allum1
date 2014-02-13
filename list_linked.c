/*
** list_linked.c for push_swap in /home/sebastien/travaux/push_swap
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Sat Dec 21 19:51:22 2013 Sebastien Chapuis
** Last update Thu Feb 13 13:59:38 2014 chapui_s
*/

#include <stdlib.h>
#include "allum.h"

t_allum		*create_list(int nb)
{
  t_allum	*new;

  new = NULL;
  if ((new = (t_allum*)malloc(sizeof(*new))))
  {
    new->nb = nb;
    new->is_select = 0;
    new->prec = NULL;
    new->next = NULL;
  }
  else
    puterror(ERROR_MALLOC);
  return (new);
}

int		push_back(t_allum **root, int nb)
{
  t_allum	*new;
  t_allum	*tmp;

  tmp = *root;
  new = create_list(nb);
  if (new)
  {
    new->prec = tmp->prec;
    new->next = tmp;
    tmp->prec->next = new;
    tmp->prec = new;
    (*root)->nb_elem = (*root)->nb_elem + 1;
    return (0);
  }
  return (-1);
}

int	init_root(t_allum **root)
{
  if ((*root = (t_allum*)malloc(sizeof(**root))) == NULL)
  {
    puterror(ERROR_MALLOC);
    return (-1);
  }
  (*root)->is_select = 0;
  (*root)->nb_elem = 0;
  (*root)->next = (*root);
  (*root)->prec = (*root);
  return (0);
}

void		free_list(t_allum *root)
{
  t_allum	*tmp;
  t_allum	*tmp2;

  tmp = root->next;
  while (tmp != root)
  {
    tmp2 = tmp->next;
    free_list(tmp);
    tmp = tmp2;
  }
  free(tmp);
}
