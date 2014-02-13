/*
** cmd.c for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sat Feb  8 12:55:44 2014 chapui_s
** Last update Thu Feb 13 14:01:09 2014 chapui_s
*/

#include <unistd.h>
#include "allum.h"

static int	do_func(char *buf, t_func *list_func, t_allum *allum)
{
  void		(*func_tmp)(t_allum *allum);

  while (list_func && my_strcmp(buf, list_func->keycode) != 0)
    list_func = list_func->next;
  if (list_func)
  {
    func_tmp = (list_func)->func_ptr;
    func_tmp(allum);
  }
  return (0);
}

int	cmd(char *buffer, t_func *list_func, t_allum *allum, t_info *info)
{
  int	check_read;

  buf_zero(buffer, BUF_SIZE);
  if ((check_read = read(0, buffer, BUF_SIZE)) < 0)
    return (puterror(ERROR_READ));
  else if ((buffer[0] == 27 && buffer[1] == 0) || check_read == 0)
  {
    my_putstr(GOODBYE);
    return (0);
  }
  if (buffer[0] == ' ' && buffer[1] == 0)
  {
    rm_matches(allum);
    if (is_continue(allum, IA_TURN, info) == 0)
      return (0);
    ia_turn(allum, info);
  }
  else
    do_func(buffer, list_func, allum);
  return (1);
}
