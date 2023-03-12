NAME = vector

SRC = 	srcs/vector.c \
		srcs/util.c

INCLUDE = -I ./includes
OBJ = $(SRC:%.c=%.o)


CFLAGS = -Wall -Werror -Wextra

all: build

build:
	$(MAKE) -j4 $(NAME)

$(NAME): $(OBJ)
	clang $(OBJ) -o $(NAME) -g -fsanitize=address

%.o: %.c
	clang -c  $(INCLUDE) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all