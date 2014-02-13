/*
** init_keys.c for my_select in /home/sebastien/travaux/my_select
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Thu Jan 16 18:26:03 2014 sebastien
** Last update Thu Feb 13 10:54:33 2014 chapui_s
*/

#include <stdlib.h>

char	*init_up(void)
{
  char	*keycode;

  if ((keycode = (char*)malloc(4)))
  {
    keycode[0] = 27;
    keycode[1] = 91;
    keycode[2] = 65;
    keycode[3] = 0;
  }
  return (keycode);
}

char	*init_down(void)
{
  char	*keycode;

  if ((keycode = (char*)malloc(4)))
  {
    keycode[0] = 27;
    keycode[1] = 91;
    keycode[2] = 66;
    keycode[3] = 0;
  }
  return (keycode);
}

char	*init_more(void)
{
  char	*keycode;

  if ((keycode = (char*)malloc(4)))
  {
    keycode[0] = 27;
    keycode[1] = 91;
    keycode[2] = 68;
    keycode[3] = 0;
  }
  return (keycode);
}

char	*init_less(void)
{
  char	*keycode;

  if ((keycode = (char*)malloc(4)))
  {
    keycode[0] = 27;
    keycode[1] = 91;
    keycode[2] = 67;
    keycode[3] = 0;
  }
  return (keycode);
}
