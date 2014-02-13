/*
** allum.h for allum1 in /home/sebastien/travaux/allum1
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Feb  6 11:37:10 2014 chapui_s
** Last update Thu Feb 13 14:00:53 2014 chapui_s
*/

#ifndef ALLUM_H_
# define ALLUM_H_

# include <term.h>

typedef struct		s_info
{
  unsigned int		nb_allum;
  unsigned int		nb_rang;
  unsigned int		a_mod;
  unsigned int		r_mod;
  unsigned int		difficultie;
  unsigned int		mode;
}			t_info;

typedef struct		s_allum
{
  int			nb;
  unsigned int		is_select;
  unsigned int		nb_select;
  unsigned int		nb_elem;
  struct s_allum	*prec;
  struct s_allum	*next;
}			t_allum;

typedef struct		s_func
{
  char			*keycode;
  void			(*func_ptr)(t_allum *allum);
  struct s_func		*next;
}			t_func;

# define TERM_BUF_SIZE	4096
# define BUF_SIZE	64
# define IA_TURN	1
# define PLAYER_TURN	0
# define EASY		0
# define HARD		1
# define NORMAL		0
# define MISERE		1
# define SIZE_MENU	60
# define COLOR_MENU	\033[32m
# define GOODBYE	"See you soon\n"
# define ERROR_MALLOC	"error: could not alloc\n"
# define ERROR_READ	"error: could not read\n"

int		my_strcmp(char *s1, char *s2);
int		puterror(char *s);
int		my_atoi(char *str);
int		is_number(char *s);
void		my_putstr(char *s);
void		my_tputs(char *s);
void		my_putchar(char c);
void		my_putnbr(int n);
int		init_term(char **env,
			  struct termios *term_attr);
int		restore_term(struct termios *term_attr,
			     char **menu_ptr,
			     t_func *list_func,
			     t_allum *allum);
char		*get_term(char **env);
int		play(t_allum *allum, t_func *list_func, t_info *info);
t_allum		*manage_nb(t_info *info_arg, t_allum *allum);
int		push_back(t_allum **root, int nb);
int		init_root(t_allum **root);
int		insert_rest(t_allum *root, int nb);
t_allum		*create_list(int nb);
void		disp_allum(t_allum *allum);
void		move_up(t_allum *allum);
void		move_down(t_allum *allum);
void		less_matches(t_allum *allum);
void		more_matches(t_allum *allum);
void		rm_matches(t_allum *allum);
void		buf_zero(char *buf, unsigned int size);
char		*init_up(void);
char		*init_down(void);
char		*init_more(void);
char		*init_less(void);
t_func		*init_func(void);
int		cmd(char *buffer,
		    t_func *list_func,
		    t_allum *allum,
		    t_info *info);
int		menu(t_info *info, char **menu, int tab_current);
void		put_empty(char c, int is_empty);
void		t_choice(char **menu,
			 int tab_menu[4],
			 int i,
			 int tab_current);
void		putm(char *str, int color);
void		putm_nb(int nb, int is_match, int tab_current);
void		disp_nb(t_info *info, int tab_current);
void		get_select(char *buffer, int *tab_current, int tab_menu[4]);
void		disp_menu(t_info *info,
                          char **menu,
                          int tab_menu[4],
                          int tab_current);
void		get_nb(char *buffer, t_info *info, int tab_current);
void		ia_turn(t_allum *allum, t_info *info);
int		add_r(t_allum *root, int rang_to_get);
int		is_continue(t_allum *allum, int who, t_info *info);
void		put_choice(char **menu,
			   int tab_menu[4],
			   int i,
			   int tab_current);
void		move_select(int tab_current, int tab_menu[4]);
void		mod_nb(t_info *info, int tab_current, char c);
void		rm_less_one(t_allum *allum);
void		rm_nb_allum(unsigned int allum_to_keep,
			    unsigned int line_to_mod,
			    t_allum *allum);
void		rm_greater(t_allum *allum,
			   unsigned int nb_one);
void		reselect(t_allum *allum);
void		free_prog(char **menu_ptr,
			  t_func *list_func,
			  t_allum *allum);

#endif /* !ALLUM_H_ */
