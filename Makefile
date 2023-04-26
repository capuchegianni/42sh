##
## EPITECH PROJECT, 2022
## PROJECT_NAME
## File description:
## Makefile to compile project_name
##

NAME = 42sh

SRC = 	src/main.c												\
		src/termios/sh42.c										\
		src/termios/inits/init_shell.c 							\
		src/termios/inits/init_env.c 							\
		src/termios/inits/init_history.c 						\
		src/termios/special_chars/newline.c 					\
		src/termios/special_chars/delete.c 						\
		src/termios/special_chars/keys.c 						\
		src/termios/special_chars/scan_input.c 					\
		src/termios/special_chars/tab.c 						\
		src/termios/parsing/parsing.c 							\
		src/termios/parsing/check_cmd.c 						\
		src/termios/utils/free_struct_shell.c 					\
		src/termios/utils/prompt.c 								\
		src/termios/commands/alias/alias.c						\
		src/termios/commands/history/history.c 					\
		src/termios/commands/history/history_error_handling.c 	\
		src/termios/commands/history/print_history.c 			\
		src/termios/commands/cd/change_pwd.c					\
		src/termios/commands/cd/cd_cmd.c 						\
		src/termios/commands/env_cmds/env.c 					\
		src/termios/commands/env_cmds/setenv.c 					\
		src/termios/commands/env_cmds/unsetenv.c 				\
		src/termios/commands/execve_handling/basic_cmds.c 		\

OBJ_DIR = ./obj/

OBJ = $(addprefix $(OBJ_DIR), $(subst src/,,$(SRC:.c=.o)))

WARNING_FLAGS := -Wall -Wextra -W -g -g3 -ggdb -Wno-unused-parameter

LIB_FLAGS := -I include/ -L ./lib/my -l:libmy.a

FILE = coding-style.sh

all: $(OBJ_DIR) $(NAME)

build_lib:
	make -C lib/my/

$(NAME): $(OBJ)
	make build_lib
	gcc $(SRC) $(WARNING_FLAGS) -o $(NAME) $(LIB_FLAGS)
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

cstyle: fclean
	FILE=$$(find ~/ -name "$(FILE)" -print -quit); \
	if [ -z "$$FILE" ]; then \
		echo "[ \e[1;93mWARNING\e[0m ]" \
		"\e[1;31mFile $(FILE) not found.\e[0m"; \
		exit 69; \
	else \
		bash $$FILE . .; \
	fi
	if [ -s coding-style-reports.log ]; then \
		echo "[ \e[1;93mWARNING\e[0m ]" \
		"\e[1;31mFound coding style errors in coding-style-reports.log\e[0m"; \
		cat coding-style-reports.log; \
	else \
		echo "[ \e[1;34mOK\e[0m ]" \
		"\e[1;32mNo coding style error found\e[0m"; \
		rm -f coding-style-reports.log; \
	fi

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
