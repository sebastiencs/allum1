##
## Makefile for Makefile in /home/sebastien/travaux/allum1
## 
## Made by chapui_s
## Login   <chapui_s@epitech.eu>
## 
## Started on  Thu Feb  6 11:39:35 2014 chapui_s
## Last update Thu Feb 13 14:04:11 2014 chapui_s
##

SRC	= main.c \
	  utils.c \
	  my_puts.c \
	  mod_term.c \
	  play.c \
	  list_linked.c \
	  mod_list.c \
	  disp.c \
	  move.c \
	  init_keys.c \
	  list_func.c \
	  cmd.c \
	  menu.c \
	  disp_menu.c \
	  menu_put.c \
	  ia.c \
	  manage_allum.c \
	  free.c

NAME	= allum1

CFLAGS	= -lncurses

OBJ	= $(SRC:.c=.o)

CC	= gcc

RM	= rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
