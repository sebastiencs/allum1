/*
** list_menu.c for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sat Feb  8 16:46:27 2014 chapui_s
** Last update Sat Feb  8 16:54:13 2014 chapui_s
*/

char	*init_menu(void)
{
  char	menu_string[5][50];

  menu_string[1] = "Easy\n";
  menu_string[2] = "Hard (default)\n";
  menu_string[3] = "Normal: the last who takes a match win\n";
  menu_string[4] = "Misere: the last who takes a match lose (default)\n";
  menu_string[5] = 0;
  return (&(menu_string[0][0]));
}
