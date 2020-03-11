NAME = ft_ls.a

FLAGS = -g -Wall -Wextra -Werror -c

SRC = ./ft_ls.c

OBJS = ./ft_ls.o

all: $(NAME)

$(NAME):
		gcc $(FLAGS) $(SRC) 
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		rm -f $(OBJS)

fclean:
		rm -f $(NAME)

re: fclean all

lin:
		gcc -o ft_ls test.c ft_ls.a ./libft/libft.a

.PHONY: re, fclean, clean, all