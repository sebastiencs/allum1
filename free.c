/*
** free.c for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Feb 13 13:33:55 2014 chapui_s
** Last update Thu Feb 13 13:50:15 2014 chapui_s
*/

#include <stdlib.h>
#include "allum.h"

void		free_prog(char **menu_ptr,
			  t_func *list_func,
			  t_allum *allum)
{
  t_func	*tmp_func;
  t_allum	*tmp1_allum;
  t_allum	*tmp2_allum;

  free(menu_ptr);
  while (list_func)
  {
    tmp_func = list_func->next;
    free(list_func->keycode);
    free(list_func);
    list_func = tmp_func;
  }
  tmp1_allum = allum->next;
  while (tmp1_allum != allum)
  {
    tmp2_allum = tmp1_allum->next;
    free(tmp1_allum);
    tmp1_allum = tmp2_allum;
  }
  free(allum);
}
