CFLAGS = -Wall -Wextra -Werror

NAME = ft_ls

SRC = ft_ls.c

OBJ = ft_ls.o

all: $(NAME)

$(NAME):
	@gcc -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib	$(NAME)

clean:
	@rm *.o

fclean: clean
	@rm $(NAME)
 
re : fclean all 