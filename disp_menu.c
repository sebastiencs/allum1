/*
** disp_menu.c for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Wed Feb 12 19:48:42 2014 chapui_s
** Last update Thu Feb 13 13:09:39 2014 chapui_s
*/

#include <stdlib.h>
#include <unistd.h>
#include "allum.h"

void		disp_nb(t_info *info, int tab_current)
{
  putm("             NB MATCHES   (16 by default, 1000 max)", 1);
  putm_nb(info->nb_allum, 1, tab_current);
  put_empty('|', 1);
  putm("             NB ROWS      (4 by default,  35 max)", 1);
  putm_nb(info->nb_rang, 0, tab_current);
}

void		disp_menu(t_info *info,
			  char **menu,
			  int tab_menu[4],
			  int tab_current)
{
  int		i;

  i = 0;
  my_tputs(tgetstr("cl", NULL));
  put_empty('-', 0);
  put_empty('|', 1);
  putm("                       ALLUM1", 1);
  put_empty('|', 1);
  while (i < 4)
  {
    (i == 0 || i == 2) ? (put_empty('|', 1)) : (0);
    (i == 0) ? (putm("             DIFFICULTIE", 1)) : (0);
    (i == 2) ? (putm("             MODE", 1)) : (0);
    (i == 0 || i == 2) ? (put_empty('|', 1)) : (0);
    put_choice(menu, tab_menu, i, tab_current);
    i += 1;
  }
  put_empty('|', 1);
  disp_nb(info, tab_current);
  put_empty('|', 1);
  put_empty('|', 1);
  putm("             SELECT WITH SPACE, ENTER TO VALID", 1);
  put_empty('|', 1);
  put_empty('-', 0);
}


void		get_select(char *buffer, int *tab_current, int tab_menu[4])
{
  if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 65
      && buffer[3] == 0)
    (*tab_current > 0) ? ((*tab_current) -= 1) : (0);
  else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 66
	   && buffer[3] == 0)
    (*tab_current < 5) ? ((*tab_current) += 1) : (0);
  else if (buffer[0] == ' ' && buffer[1] == 0)
    move_select(*tab_current, tab_menu);
}

void		get_nb(char *buffer, t_info *info, int tab_current)
{
  if ((buffer[0] >= '0' && buffer[0] <= '9') || (buffer[0] == 127))
    mod_nb(info, tab_current, buffer[0]);
}
