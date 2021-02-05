NAME = generator
LIB = libmapgen.a
SRC = main.c args.c build.c

all: $(NAME) $(LIB)

$(NAME):
	clang -Wall -Wextra -Werror $(SRC) -o $(NAME)

$(LIB):
	clang -Wall -Wextra -Werror -c build.c
	ar rc $(LIB) build.o
	ranlib $(LIB)

clean:
	rm -f build.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re
