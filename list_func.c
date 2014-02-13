/*
** list_func.c for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sat Feb  8 13:11:43 2014 chapui_s
** Last update Thu Feb 13 13:59:15 2014 chapui_s
*/

#include <stdlib.h>
#include "allum.h"

static t_func	*create_func(char *keycode,
			     void (*func_ptr)(t_allum *allum))
{
  t_func	*new;

  new = NULL;
  if ((new = (t_func*)malloc(sizeof(*new))))
  {
    new->keycode = keycode;
    new->func_ptr = func_ptr;
    new->next = NULL;
  }
  return (new);
}

static int	push_func(t_func **list, char *keycode,
			  void (*func_ptr)(t_allum *allum))
{
  t_func	*tmp;

  tmp = *list;
  if (*list)
  {
    while (tmp->next)
      tmp = tmp->next;
    if ((tmp->next = create_func(keycode, func_ptr)))
      return (0);
  }
  else
    if ((*list = create_func(keycode, func_ptr)))
      return (0);
  puterror(ERROR_MALLOC);
  return (-1);
}

static char	*get_keycode(int i)
{
  char		*keycode;

  keycode = NULL;
  (i == 0) ? (keycode = init_up()) : (0);
  (i == 1) ? (keycode = init_down()) : (0);
  (i == 2) ? (keycode = init_more()) : (0);
  (i == 3) ? (keycode = init_less()) : (0);
  if (keycode == NULL)
    puterror(ERROR_MALLOC);
  return (keycode);
}

static void	get_func(void (**func_ptr)(t_allum *allum), int i)
{
  (i == 0) ? (*func_ptr = &move_up) : (0);
  (i == 1) ? (*func_ptr = &move_down) : (0);
  (i == 2) ? (*func_ptr = &more_matches) : (0);
  (i == 3) ? (*func_ptr = &less_matches) : (0);
}

t_func		*init_func(void)
{
  t_func	*list_func;
  int		i;
  char		*keycode;
  void		(*func_ptr)(t_allum *allum);

  i = 0;
  list_func = NULL;
  while (i < 4)
  {
    get_func(&func_ptr, i);
    if ((keycode = get_keycode(i)) == NULL)
      return (NULL);
    if ((push_func(&list_func, keycode, func_ptr)) == -1)
      return (NULL);
    i = i + 1;
  }
  return (list_func);
}
