NAME		=	push_swap

SRCS_FILES	= 	push_swap.c make_arr.c errors.c init.c\
				swap.c push.c rotate.c reverse.c\
				sorting.c stats.c full_sort.c\
				sort_help.c put_a.c

SRCS		= 	$(SRCS_FILES)
OBJS		=	$(patsubst %.c,%.o,$(SRCS))

INCLUDE		=	-I.

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -f

LIB = ./libft/libft.a

.PHONY:		all libft clean fclean re

all:		libft $(NAME)

libft:
	@$(MAKE) -C $(dir $(LIB))

%.o:		%.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME):	$(OBJS) $(LIB)
			$(CC) $(INCLUDE) $(LIB) -o $(NAME) $(OBJS)

clean:
			@$(RM) $(OBJS)
			@$(MAKE) -C $(dir $(LIB)) clean

fclean:		clean
			@$(MAKE) -C $(dir $(LIB)) fclean
			@$(RM) $(NAME)

re:			fclean all

