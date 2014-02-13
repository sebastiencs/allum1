/*
** menu_put.c for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Wed Feb 12 19:45:16 2014 chapui_s
** Last update Thu Feb 13 10:59:57 2014 chapui_s
*/

#include <stdlib.h>
#include <unistd.h>
#include "allum.h"

void		put_empty(char c, int is_empty)
{
  int		i;

  i = 0;
  my_putstr("\033[32m  ");
  my_putchar(c);
  if (is_empty == 1)
    my_putstr("\033[0m");
  while (i < SIZE_MENU)
  {
    my_putchar((is_empty == 1) ? (' ') : (c));
    i = i + 1;
  }
  my_putstr("\033[32m");
  my_putchar(c);
  my_putstr("\033[0m");
  my_putchar('\n');
}

void		put_choice(char **menu,
			   int tab_menu[4],
			   int i,
			   int tab_current)
{
  int		j;

  j = 0;
  my_putstr("\033[32m  |     \033[0m");
  if (tab_menu[i] == 1)
    my_tputs(tgetstr("so", NULL));
  if (tab_current == i)
    my_tputs(tgetstr("us", NULL));
  while (menu[i][j] != 0)
  {
    my_putchar(menu[i][j]);
    j += 1;
  }
  if (tab_menu[i] == 1)
    my_tputs(tgetstr("se", NULL));
  if (tab_current == i)
    my_tputs(tgetstr("ue", NULL));
  while (j++ < SIZE_MENU - 7)
    my_putchar(' ');
  my_putstr("\033[32m  |\033[0m\n");
}

void		putm(char *str, int color)
{
  int		i;

  i = 0;
  (color == 1) ? (write(1, "\033[32m", 5)) : (0);
  my_putstr("  |");
  while (str[i])
    write(1, &str[i++], 1);
  while (i < SIZE_MENU)
  {
    write(1, " ", 1);
    i = i + 1;
  }
  write(1, "|", 1);
  (color == 1) ? (write(1, "\033[0m", 5)) : (0);
  write(1, "\n", 1);
}

void		putm_nb(int nb, int is_match, int tab_current)
{
  int		i;
  int		size_nb;

  i = 0;
  size_nb = 0;
  my_putstr("\033[32m  |     \033[0m");
  if ((is_match == 1 && tab_current == 4)
      || (is_match == 0 && tab_current == 5))
    my_tputs(tgetstr("us", NULL));
  my_putnbr(nb);
  if ((is_match == 1 && tab_current == 4)
      || (is_match == 0 && tab_current == 5))
    my_tputs(tgetstr("ue", NULL));
  while (nb > 0)
  {
    nb = nb / 10;
    size_nb += 1;
  }
  i = size_nb;
  (i == 0) ? (i = 1) : (0);
  while (i++ < SIZE_MENU - 7)
    write(1, " ", 1);
  my_putstr("\033[32m  |\033[0m");
  write(1, "\n", 1);
}
