NAME = vector

SRC = 	vector.c \
		util.c

INCLUDE = includes
OBJ	=$(addprefix obj/, $(SRC:.c=.o))
OBJ_DIR = obj

CFLAGS += -Wall -Werror -Wextra

ifdef FSAN
	CFLAGS += -g -fsanitize=address
endif

all: build

fsan:
	FSAN=1 make re

build:
	@$(MAKE) -j4 $(NAME)

$(NAME): $(OBJ)
	@clang $(OBJ) $(CFLAGS) -I$(INCLUDE) -o $(NAME)

$(OBJ_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@printf "$(GREEN)Compiling: $(RESET)$(notdir $<)\n"
	@clang -c $(CFLAGS) -I$(INCLUDE) -o $@ $<

clean:
	@printf "$(GREEN)Compiling: $(RESET)$(notdir $(OBJ))\n"
	@rm -f $(OBJ)

fclean: clean
	@printf "$(GREEN)Compiling: $(RESET)$(notdir $(NAME))\n"
	@rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re

GREEN			:=	\033[1;32m
RESET			:= \033[0m