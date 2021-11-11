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
CFLAGS	=	-Wall -Wextra -Werror -I.$(HEADERS)
# Флаги + подкл. хедера к сборке, чтобы подгрузились правильные зависимости программ

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):	$(OBJ) $(HEADERS)
	@ar rcs $(NAME) $?
	@echo "\033[36;1m\n< Compiled libft >\n\033[0m"
# $? - Имена всех пререквизитов (разделенные пробелами), которые являются "более новыми", чем цель.

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
# $< - Имя первого пререквизита.
# $@ - Имя файла цели правила. Если цель является элементом архива (archive member), то '$@' обозначает имя архивного файла.

clean:
	@rm -f $(OBJ) $(OBJ_B)

fclean:	clean
	@$(RM) $(NAME)

re: fclean all