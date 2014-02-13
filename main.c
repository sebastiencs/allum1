/*
** main.c for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Feb  6 11:08:50 2014 chapui_s
** Last update Thu Feb 13 13:21:16 2014 chapui_s
*/

#include <stdlib.h>
#include <term.h>
#include "allum.h"

static void	init_info(t_info *info_arg)
{
  info_arg->nb_allum = 16;
  info_arg->a_mod = 0;
  info_arg->nb_rang = 4;
  info_arg->r_mod = 1;
}

static int	get_arg(int argc, char **argv, t_info *info_arg)
{
  int		i;

  i = 1;
  init_info(info_arg);
  while (i < argc)
  {
    if (my_strcmp(argv[i], "-h") == 0
	|| my_strcmp(argv[i], "--help") == 0)
    {
      my_putstr("./allum1 [--help]\n\t[ESC] to leave the game\n");
      return (-1);
    }
    else
    {
      my_putstr("bad args:\n");
      my_putstr("./allum1 --help\n");
      return (-1);
    }
    i += 1;
  }
  return (0);
}

int			main(int argc, char **argv, char **env)
{
  struct termios	term_attr;
  char			**menu_ptr;
  t_func		*list_func;
  t_info		info;
  t_allum		*allum;

  menu_ptr = NULL;
  if ((list_func = init_func()) == NULL)
    return (-1);
  if (get_arg(argc, argv, &info) == -1)
    return (-1);
  if ((init_term(env, &term_attr)) == -1)
    return (-1);
  if ((init_root(&allum)) == -1)
    return (-1);
  if ((menu(&info, menu_ptr, 1)) == 0)
  {
    if ((allum = manage_nb(&info, allum)) == NULL)
      return (-1);
    allum->prec->is_select = 1;
    allum->prec->nb_select = allum->prec->nb;
    play(allum, list_func, &info);
  }
  restore_term_and_free(&term_attr, menu_ptr, list_func, allum);
  return (0);
}
