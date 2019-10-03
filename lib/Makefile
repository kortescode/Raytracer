##
## Makefile for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/lib
## 
## Made by henri hardillier
## Login   <hardil_h@epitech.net>
## 
## Started on  Thu Jun  2 15:02:41 2011 henri hardillier
## Last update Sun Jun  5 23:31:20 2011 henri hardillier
##

CC	=	gcc
AR	=	ar rc
RAN	=	ranlib
RM	=	rm -f
PRINT	=	printf

NAME	=	libmy.a

FOLDER	=	./srcs/

CFLAGS	+=	-W -Wall -Wextra -Werror
CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-I./include/ -I/usr/X11/include/

SRCS	=	$(FOLDER)xopen.c		\
		$(FOLDER)xfree.c		\
		$(FOLDER)get_next_line.c	\
		$(FOLDER)my_getnbr_base.c	\
		$(FOLDER)my_worldtab.c		\
		$(FOLDER)xsignal.c		\
		$(FOLDER)xmalloc.c		\
		$(FOLDER)my_strupcase.c		\
		$(FOLDER)xclose.c		\
		$(FOLDER)xwrite.c		\
		$(FOLDER)xread.c		\
		$(FOLDER)xmlx_init.c		\
		$(FOLDER)xmlx_new_window.c	\
		$(FOLDER)xmlx_new_image.c	\
		$(FOLDER)my_strlowcase.c	\
		$(FOLDER)my_char.c		\
		$(FOLDER)my_char_repeat.c	\
		$(FOLDER)my_putnbr.c		\
		$(FOLDER)my_stradd.c		\
		$(FOLDER)my_strcpy.c		\
		$(FOLDER)my_strdup.c		\
		$(FOLDER)my_write.c		\
		$(FOLDER)my_match_exp.c		\
		$(FOLDER)my_putstr.c

OBJS	=	$(SRCS:.c=.o)

$(NAME)	:	$(OBJS)
		@$(AR) $(NAME) $(OBJS)
		@$(RAN) $(NAME)
		@$(RM) $(OBJS)
		@$(PRINT) "\033[32m*** Lib $(NAME) is compiled ***\n\033[00m"

all	:	$(NAME)

clean	:
		@$(RM) $(OBJS)
		@$(RM) *~ \#*\#
		@$(PRINT) "\033[31m*** Objects are removed ***\n\033[00m"

fclean	:	clean
		@$(RM) $(NAME)
		@$(PRINT) "\033[31m*** Lib $(NAME) is removed ***\n\033[00m"

re	:	fclean all

.PHONY	:	all clean fclean re