/*
** utils.c for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Feb  6 11:44:21 2014 chapui_s
** Last update Sat Feb  8 12:51:27 2014 chapui_s
*/

#include <unistd.h>

int	my_strcmp(char *s1, char *s2)
{
  return ((*s1 == *s2 && *s1) ? (my_strcmp(++s1, ++s2)) : (*s1 - *s2));
}

int	my_atoi(char *str)
{
  int	i;
  int	negativ;
  int	number;

  i = 0;
  negativ = 0;
  number = 0;
  while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
	 || (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
    i++;
  if (str[i] == 45)
    negativ = 1;
  if ((str[i] == 45) || (str[i] == 43))
    i++;
  while (str[i] >= 48 && str[i] <= 57)
  {
    number *= 10;
    number += ((int)str[i] - 48);
    i++;
  }
  if (negativ == 1)
    return (-number);
  else
    return (number);
}

int	is_number(char *s)
{
  int	i;

  i = 0;
  if (!s)
    return (-1);
  while (s[i])
  {
    if (s[i] < '0' || s[i] > '9')
      return (-1);
    i += 1;
  }
  return (0);
}

char	*get_term(char **env)
{
  int	i;

  i = 0;
  if (env == NULL || env[0] == NULL)
    return (NULL);
  while (env[i])
  {
    if (env[i][0] == 'T' && env[i][1] == 'E' && env[i][2] == 'R'
        && env[i][3] == 'M' && env[i][4] == '=')
      return (&(env[i][5]));
    i = i + 1;
  }
  return (NULL);
}

void		buf_zero(char *buf, unsigned int size)
{
  unsigned int	i;

  i = 0;
  while (i < size)
  {
    buf[i] = 0;
    i += 1;
  }
}
