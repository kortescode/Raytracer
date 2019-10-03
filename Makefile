##
## Makefilex for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer
## 
## Made by henri hardillier
## Login   <hardil_h@epitech.net>
## 
## Started on  Sat Jun  4 23:23:09 2011 henri hardillier
## Last update Sun Feb  5 21:12:40 2012 henri hardillier
##

CC		=	gcc
RM		=	rm -f
PRINT		=	printf
MAKE		=	make -C
NORME		=	/u/all/astek/public/norme/norme -nocheat

NAME		=	rt

MAIN		=	./main/
MLX		=	./mlx/
LOADER		=	./loader/
PARSER		=	./parser/
INTER		=	./inter/
K		=	./k/
MOVEMENTS	=	./movements/
EFFECTS		=	./effects/
LIMITS		=	./limits/
LIB		=	./lib/
SAVE		=	./save/

CFLAGS		+=	-W -Wall -Wextra -Werror
CFLAGS		+=	-ansi -pedantic
CFLAGS		+=	-D_BSD_SOURCE
CFLAGS		+=	-I./include/ -I./lib/include/ -I/usr/X11/include

LDFLAGS		+=	-L./lib/ -lmy
LDFLAGS		+=	-L/usr/X11/lib -lmlx -lXext -lX11 -lm

SRCS		=	$(MAIN)main.c			\
			$(MAIN)fill_image.c		\
			$(MAIN)get_color.c		\
			$(MLX)gere.c			\
			$(MLX)mlx.c			\
			$(MLX)pixel_put_to_image.c	\
			$(LOADER)loader.c		\
			$(PARSER)check_eye.c		\
			$(PARSER)check_mlx.c		\
			$(PARSER)check_object.c		\
			$(PARSER)check_spot.c		\
			$(PARSER)error_is_num.c		\
			$(PARSER)error_object.c		\
			$(PARSER)get_config.c		\
			$(PARSER)init_values.c		\
			$(PARSER)set_eye_values.c	\
			$(PARSER)set_mlx_values.c	\
			$(PARSER)set_obj_effects.c	\
			$(PARSER)set_obj_values.c	\
			$(PARSER)set_spot_values.c	\
			$(PARSER)stock.c		\
			$(PARSER)define_color.c		\
			$(PARSER)set_limit_min.c	\
			$(PARSER)set_limit_max.c	\
			$(PARSER)init_limit.c		\
			$(INTER)inter.c			\
			$(INTER)plan.c			\
			$(INTER)sphere.c		\
			$(INTER)cylinder.c		\
			$(INTER)cone.c			\
			$(INTER)paraboloid.c		\
			$(INTER)hyperboloid.c		\
			$(K)delta_calcul.c		\
			$(K)plan.c			\
			$(K)sphere.c			\
			$(K)cylinder.c			\
			$(K)cone.c			\
			$(K)paraboloid.c		\
			$(K)hyperboloid.c		\
			$(MOVEMENTS)translation.c	\
			$(MOVEMENTS)rotations.c		\
			$(EFFECTS)color.c		\
			$(EFFECTS)luminosity.c		\
			$(EFFECTS)shadows.c		\
			$(EFFECTS)reflection.c		\
			$(EFFECTS)transparency.c	\
			$(EFFECTS)save_restore_values.c	\
			$(LIMITS)limits.c		\
			$(LIMITS)sphere.c		\
			$(LIMITS)cylinder.c		\
			$(LIMITS)cone.c			\
			$(LIMITS)paraboloid.c		\
			$(LIMITS)hyperboloid.c		\
			$(SAVE)save.c			\
			$(SAVE)xcolor_change.c		\
			$(SAVE)xcolor_it.c		\
			$(SAVE)xload_fill_bar.c		\
			$(SAVE)xload_percent.c		\
			$(SAVE)xload_get_word.c

OBJS		=	$(SRCS:.c=.o)

$(NAME)		:	$(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)
			@$(PRINT) "\033[32m*** Compilation of $(NAME) done ***\n\033[00m"

all		:	lib $(NAME)

clean		:
			@$(RM) $(OBJS)
			@$(RM) *~ \#*\#
			@$(PRINT) "\033[31m*** Objects are removed ***\n\033[00m"

fclean		:	clean
			@$(RM) $(NAME)
			@$(PRINT) "\033[31m*** Binary $(NAME) is removed ***\n\033[00m"

re		:	fclean all

lib		:
			@$(MAKE) $(LIB)

norme		:
			@$(NORME) $(SRCS)

.PHONY		:	all clean fclean re lib norme
