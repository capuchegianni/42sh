##
## EPITECH PROJECT, 2022
## lib-epitech
## File description:
## lib Makefile
##

NAME = libmy.a

SRC = 	my_casesensitive.c 				\
		my_cleanstr.c 					\
		my_findprimesup.c 				\
		my_free_wordarray.c 			\
		my_getnbr.c 					\
		my_isneg.c 						\
		my_isnum.c 						\
		my_isprime.c 					\
		my_memcpy.c 					\
		my_pow.c 						\
		my_printerr.c 					\
		my_printf.c 					\
		my_putchar.c 					\
		my_putnbr.c 					\
		my_putstr.c 					\
		my_readfile.c 					\
		my_realloc.c 					\
		my_revstr.c 					\
		my_rmtabline.c 					\
		my_sortintarray.c 				\
		my_sqrt.c 						\
		my_strcat.c 					\
		my_strcmp.c 					\
		my_strcpy.c 					\
		my_strdup.c 					\
		my_strisalpha.c 				\
		my_strlen.c						\
		my_strncat.c 					\
		my_strncmp.c 					\
		my_strncpy.c 					\
		my_strstr.c 					\
		my_swap.c 						\
		my_tablen.c						\
		my_tostr.c						\
		my_wordarray.c 					\

OBJ_DIR = ../../obj/

OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

WARNING_FLAGS := -Wall -Wextra -W -g -g3 -ggdb

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	@echo -n "[ "
	@echo -n "\e[1;34mOK\e[0m"
	@echo -n " ] "
	@echo "\e[1;32mSuccessfully compiled libmy\e[0m"

$(OBJ_DIR)%.o: %.c
	gcc -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
