NAME		=	pipex

SRCS_FILES	= 	pipex.c\
				utils.c

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
			@echo "\033[36;1m\n< Compiled pipex >\n\033[0m"
			@echo "\033[36;1m\n< Done >\n\033[0m"

clean:
			@$(RM) $(OBJS)
			@$(MAKE) -C $(dir $(LIB)) clean
			@echo "\033[32;1m\n< Cleaning succeed >\n\033[0m"

fclean:		clean
			@$(MAKE) -C $(dir $(LIB)) fclean
			@$(RM) $(NAME)
			@echo "\033[32;1m\n< All created files were deleted >\n\033[0m"

re:			fclean all
			@echo "\033[35;1m\n< Remake done >\n\033[0m"
