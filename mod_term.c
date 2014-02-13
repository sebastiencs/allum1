/*
** mod_term.c for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Feb  6 12:50:26 2014 chapui_s
** Last update Thu Feb 13 13:47:07 2014 chapui_s
*/

#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include "allum.h"

int     init_term(char **env,
		  struct termios *term_attr)
{
  char	term_buf[TERM_BUF_SIZE];
  char	*term_name;

  if ((term_name = get_term(env)) == NULL)
    return (puterror("error: could not determine your terminal\n"));
  if ((tgetent(term_buf, term_name)) <= 0)
  {
    puterror("error: could not find termcap database or \"");
    puterror(term_name);
    puterror("\" is not specified\n");
    return (-1);
  }
  if (tcgetattr(0, term_attr) < 0)
    return (puterror("error: could not get term values\n"));
  term_attr->c_lflag &= ~ICANON;
  term_attr->c_lflag &= ~ECHO;
  term_attr->c_cc[VMIN] = 1;
  term_attr->c_cc[VTIME] = 0;
  if ((tcsetattr(0, TCSANOW, term_attr)) < 0)
    return (puterror("error: could not set term values\n"));
  my_tputs(tgetstr("cl", NULL));
  my_tputs(tgetstr("vi", NULL));
  return (0);
}

int	restore_term_and_free(struct termios *term_attr,
			      char **menu_ptr,
			      t_func *list_func,
			      t_allum *allum)
{
  free_prog(menu_ptr, list_func, allum);
  /* void	*tmp; */
  /* void	*tmp2; */

  /* free(menu_ptr); */
  /* while (list_func) */
  /* { */
  /*   tmp = list_func->next; */
  /*   free(list_func->keycode); */
  /*   free(list_func); */
  /*   list_func = tmp; */
  /* } */
  /* tmp = allum->next; */
  /* while (tmp != allum) */
  /* { */
  /*   tmp2 = ((t_allum)tmp)->next; */
  /*   free(tmp); */
  /*   tmp = tmp2; */
  /* } */
  /* free(allum); */
  term_attr->c_lflag |= ICANON;
  term_attr->c_lflag |= ECHO;
  if ((tcsetattr(0, TCSANOW, term_attr)) == -1)
    return (puterror("error: could not set term values\n"));
  my_tputs(tgetstr("ve", NULL));
  return (0);
}
