/*
** my_puts.c for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Feb  6 12:52:37 2014 chapui_s
** Last update Thu Feb 13 13:49:25 2014 chapui_s
*/

#include <unistd.h>
#include <stdlib.h>

int	puterror(char *s)
{
  while (s && *s)
    write(2, s++, 1);
  return (-1);
}

void	my_putstr(char *s)
{
  while (s && *s)
    write(1, s++, 1);
}

void	my_tputs(char *s)
{
  if (s == NULL)
  {
    puterror("error: problem with tgetstr\n");
    exit(EXIT_FAILURE);
  }
  while (*s)
    write(1, s++, 1);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putnbr(int n)
{
  if (n < 0)
  {
    my_putchar('-');
    n = -n;
  }
  if (n >= 10)
    my_putnbr(n / 10);
  my_putchar((n % 10) + '0');
}
