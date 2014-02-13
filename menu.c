/*
** menu.c for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sat Feb  8 16:40:36 2014 chapui_s
** Last update Thu Feb 13 14:01:28 2014 chapui_s
*/

#include <stdlib.h>
#include <unistd.h>
#include "allum.h"

char	**init_menu(char **menu_string, int tab_menu[4])
{
  if ((menu_string = (char**)malloc(sizeof(char*) * 5)) == NULL)
  {
    puterror(ERROR_MALLOC);
    return (NULL);
  }
  menu_string[0] = "Easy";
  menu_string[1] = "Hard (default)";
  menu_string[2] = "Normal: the last who takes a match win";
  menu_string[3] = "Misere: the last who takes a match lose (default)";
  menu_string[4] = 0;
  tab_menu[0] = 0;
  tab_menu[1] = 1;
  tab_menu[2] = 0;
  tab_menu[3] = 1;
  return (menu_string);
}

void		move_select(int tab_current, int tab_menu[4])
{
  if (tab_current < 2)
  {
    if (tab_current == 0 && tab_menu[1] == 1)
    {
      tab_menu[0] = 1;
      tab_menu[1] = 0;
    }
    else if (tab_current == 1)
    {
      tab_menu[0] = 0;
      tab_menu[1] = 1;
    }
    return ;
  }
  if (tab_current == 2 && tab_menu[3] == 1)
  {
    tab_menu[2] = 1;
    tab_menu[3] = 0;
  }
  else if (tab_current == 3)
  {
    tab_menu[2] = 0;
    tab_menu[3] = 1;
  }
}

void		mod_nb(t_info *info, int tab_current, char c)
{
  if (c == 127)
  {
    if (tab_current == 4)
      info->nb_allum /= 10;
    else if (tab_current == 5)
      info->nb_rang /= 10;
  }
  else
  {
    if (tab_current == 4)
    {
      info->nb_allum *= 10;
      info->nb_allum += c - '0';
      (info->nb_allum > 1000) ? (info->nb_allum = 1000) : (0);
    }
    else if (tab_current == 5)
    {
      info->nb_rang *= 10;
      info->nb_rang += c - '0';
      (info->nb_rang > 35) ? (info->nb_rang = 35) : (0);
      if (info->nb_rang > info->nb_allum)
	info->nb_allum = info->nb_rang;
    }
  }
}

int		menu(t_info *info, char **menu, int tab_current)
{
  char		buffer[BUF_SIZE];
  int		ret_read;
  int		tab_menu[4];

  if ((menu = init_menu(menu, tab_menu)) == NULL)
    return (-1);
  disp_menu(info, menu, tab_menu, tab_current);
  buf_zero(buffer, BUF_SIZE);
  while ((ret_read = read(0, buffer, BUF_SIZE)) > 0 && buffer[0] != 10)
  {
    if (ret_read == -1)
      return (puterror(ERROR_READ));
    if (buffer[0] == 27 && buffer[1] == 0)
    {
      my_putstr(GOODBYE);
      return (1);
    }
    get_select(buffer, &tab_current, tab_menu);
    get_nb(buffer, info, tab_current);
    disp_menu(info, menu, tab_menu, tab_current);
    buf_zero(buffer, BUF_SIZE);
  }
  info->difficultie = (tab_menu[0] == 1) ? (EASY) : (HARD);
  info->mode = (tab_menu[2] == 1) ? (NORMAL) : (MISERE);
  return (0);
}
