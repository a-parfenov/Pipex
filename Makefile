NAME	=	pipex.a

LIB_PATH = libft/

LIB = $(LIB_PATH)libft.a

SRCS	=	pipex.c

OBJ		=	$(SRCS:%.c=%.o)
HEADERS	=	pipex.h
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I.$(HEADERS)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):	$(OBJ) $(HEADERS)
	@ar rcs $(NAME) $(LIB) $?

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIB_PATH) clean
	@rm -f $(OBJ)

fclean:	clean
	make -C $(LIB_PATH) fclean
	@$(RM) $(NAME)

re: fclean all