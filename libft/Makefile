NAME = libft.a

SRCS = 		ft_strlen.c\
			ft_strncmp.c\
			ft_split.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_memset.c\
			ft_bzero.c\
			ft_calloc.c

OBJ		=	$(SRCS:%.c=%.o)
HEADERS	=	libft.h
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I.

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):	$(OBJ) $(HEADERS)
	@ar rcs $(NAME) $?
	@echo "\033[36;1m\n< Compiled libft >\n\033[0m"

%.o : %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_B)

fclean:	clean
	@$(RM) $(NAME)

re: fclean all