##
## EPITECH PROJECT, 2022
## PROJECT_NAME
## File description:
## Makefile to compile project_name
##

NAME = 42sh

SRC = 	src/main.c							\
		src/sh42.c							\
		src/prompt.c 						\

OBJ_DIR = ./obj/

OBJ = $(addprefix $(OBJ_DIR), $(subst src/,,$(SRC:.c=.o)))

WARNING_FLAGS := -Wall -Wextra -W -g -g3 -ggdb

NCURSES_FLAGS := -lncurses

LIB_FLAGS := -I include/ -L ./lib -lmy -lncurses

all: $(OBJ_DIR) build_lib $(NAME)

build_lib:
	make -C lib/my/

$(NAME): $(OBJ)
	gcc $(SRC) $(WARNING_FLAGS) -o $(NAME) $(LIB_FLAGS) $(NCURSES_FLAGS)
	@echo -n "[ "
	@echo -n "\e[1;34mOK\e[0m"
	@echo -n " ] "
	@echo "\e[1;32mSuccessfully compiled all the files\e[0m"

$(OBJ_DIR)%.o: src/%.c
	gcc $(WARNING_FLAGS) -c -o $(OBJ_DIR)$(subst src/,,$(basename $<)).o $<	\
	$(LIB_FLAGS)

$(OBJ_DIR):
	mkdir -p $(dir $(OBJ))

clean:
	make clean -C lib/my/
	rm -f $(OBJ)
	@echo -n "[ "
	@echo -n "\e[1;34mOK\e[0m"
	@echo -n " ] "
	@echo "\e[1;32mSuccessfully removed .o & .log files\e[0m"

cstyle:
	make fclean
	../coding-style-checker/coding-style.sh . .
	../coding-style-checker/print_infos.sh

fclean: clean
	make fclean -C lib/my/
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)
	@echo -n "[ "
	@echo -n "\e[1;34mOK\e[0m"
	@echo -n " ] "
	@echo "\e[1;32mSuccessfully removed binary files\e[0m"

re: fclean all
	make clean

.PHONY: all build_lib clean cstyle fclean re
