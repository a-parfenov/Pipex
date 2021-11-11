NAME		=	pipex

SRCS_FILES	= 	pipex.c

SRCS		= 	$(SRCS_FILES)
OBJS		=	$(patsubst %.c,%.o,$(SRCS))

INCLUDE		=	-I./ -I./libs/libft/

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

LIB = ./libft/libft.a

.PHONY:		all clean fclean re

all:		$(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) $(INCLUDE) -c -g $< -o $@

$(NAME):	$(OBJS)
			@$(MAKE) -C $(dir $(LIB))
			@$(CC) $(INCLUDE) $(LIB) -o $(NAME) $(OBJS)
			@echo "\033[36;1m\n< Compiled pipex >\n\033[0m"
			@echo "\033[36;1m\n< Done >\n\033[0m"

clean:
			@$(RM) $(OBJS)
			@make -C $(dir $(LIB)) clean
			@echo "\033[32;1m\n< Cleaning succeed >\n\033[0m"

fclean:		clean
			@make -C $(dir $(LIB)) fclean
			@$(RM) $(NAME)
			@echo "\033[32;1m\n< All created files were deleted >\n\033[0m"

re:			fclean all
			@echo "\033[35;1m\n< Remake done >\n\033[0m"
