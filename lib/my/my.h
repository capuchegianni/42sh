/*
** EPITECH PROJECT, 2022
** lib-epitech
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    // Libc includes

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <stdarg.h>
    #include <string.h>
    #include <errno.h>
    #include <ncurses.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <sys/signal.h>

    /*
    *  @function my_casesensitive
    *
    *  @brief Modify a string to upper or lower case
    *  @param str string to modify
    *  @param my_case up or low as input
    *  @return char *str
    */
    char *my_casesensitive(char *str, char *my_case);

    /*
    *  @function my_cleanstr
    *
    *  @brief Remove spaces, \t and \n at the beginning and the end of a string
    *  @param str string to modify
    *  @return char *str
    */
    char *my_cleanstr(char *str);

    /*
    *  @function my_findprimesup
    *
    *  @brief Find the smallest prime number superior to a number
    *  @param nb number to compare
    *  @return int nb
    */
    int my_findprimesup(int nb);

    /*
    *  @function my_free_wordarray
    *
    *  @brief Free a word array
    *  @param array word array to free
    */
    void my_free_wordarray(char **array);

    /*
    *  @function my_getnbr
    *
    *  @brief Get a number from a string
    *  @param str string to get the number from
    *  @return int nb
    */
    int my_getnbr(char const *str);

    /*
    *  @function my_isneg
    *
    *  @brief Check if a number is negative
    *  @param nb number to check
    *  @return 1 if negative, 0 if positive
    */
    int my_isneg(int nb);

    /*
    *  @function my_isnum
    *
    *  @brief Check if a string is a number
    *  @param str string to check
    *  @return 1 if number, 0 if not
    */
    int my_isnum(char *str);

    /*
    *  @function my_isprime
    *
    *  @brief Check if a number is prime
    *  @param nb number to check
    *  @return 1 if prime, 0 if not
    */
    int my_isprime(int nb);

    /*
    *  @function my_memcpy
    *
    *  @brief Copy the adress of a pointer into another
    *  @param dest destination pointer
    *  @param src source pointer
    *  @param n size of the pointer
    *  @return void *dest
    */
    void *my_memcpy(void *dest, const void *src, size_t n);

    /*
    *  @function my_pow
    *
    *  @brief Calculate the power of a number
    *  @param nb number to use
    *  @param p power to use
    *  @return int nb
    */
    int my_pow(int nb, int p);

    /*
    *  @function my_printf
    *
    *  @brief Print a string, an int or a float
    *  @param format base string
    *  @param ... arguments to add to the string
    */
    void my_printf(const char *format, ...);

    /*
    *  @function my_putchar
    *
    *  @brief Print a character
    *  @param c character to print
    */
    void my_putchar(char c);

    /*
    *  @function my_printerr
    *
    *  @brief Print a string, an int or a float on the error output
    *  @param format base string
    *  @param ... arguments to add to the string
    */
    void my_printerr(const char *format, ...);

    /*
    *  @function my_putnbr
    *
    *  @brief Print an int
    *  @param nb number to print
    */
    void my_putnbr(long long nb);

    /*
    *  @function my_putstr
    *
    *  @brief Print a string
    *  @param str string to print
    */
    void my_putstr(char const *str);

    /*
    *  @function my_realloc
    *
    *  @brief Reallocate a pointer
    *  @param pointer pointer to reallocate
    *  @param new_size new size of the pointer
    *  @return void *pointer
    */
    void *my_realloc(void *pointer, size_t new_size);

    /*
    *  @function my_readfile_stat
    *
    *  @brief Put the content of a file in a buffer with stat
    *  @param filepath path to the file
    *  @return char *buffer
    */
    char *my_readfile(char *filepath);

    /*
    *  @function my_revstr
    *
    *  @brief Reverse a string
    *  @param str string to reverse
    *  @return char *str
    */
    char *my_revstr(char *str);

    /*
    *  @function my_rmlinetab
    *
    *  @brief Remove a line from a 2D array
    *  @param tab 2D array to modify
    *  @param line line to remove
    *  @return char **tab
    */
    char **my_rmlinetab(char **tab, int line);

    /*
    *  @function my_sortintarray
    *
    *  @brief Sort an array of int
    *  @param tab array to sort
    *  @param size size of the array
    */
    void my_sortintarray(int *tab, int size);

    /*
    *  @function my_sqrt
    *
    *  @brief Calculate the square root of a number
    *  @param nb number to use
    *  @return double nb
    */
    double my_sqrt(int nb);

    /*
    *  @function my_strcat
    *
    *  @brief Concatenate two strings
    *  @param dest destination string
    *  @param src source string
    *  @return char *dest
    */
    char *my_strcat(char *dest, char *src);

    /*
    *  @function my_cmp
    *
    *  @brief Compare two strings
    *  @param s1 first string
    *  @param s2 second string
    *  @return 0 if equal, else if not
    */
    int my_cmp(char const *s1, char const *s2);

    /*
    *  @function my_strcpy
    *
    *  @brief Copy a string into another
    *  @param dest destination string
    *  @param src source string
    *  @return char *dest
    */
    char *my_strcpy(char *dest, char const *src);

    /*
    *  @function my_strdup
    *
    *  @brief Allocate a new string and copy the content of another
    *  @param src source string
    *  @return char *new_string
    */
    char *my_strdup(char *src);

    /*
    *  @function my_strstr
    *
    *  @brief Find a string in another
    *  @param str string to search in
    *  @param to_find string to find
    *  @return char *string_found
    */
    char *my_strstr(char *str, char *to_find);

    /*
    *  @function my_strisalpha
    *
    *  @brief Check if a string is alphanumeric
    *  @param str string to check
    *  @return 1 if alpha, 0 if not
    */
    int my_strisalpha(char *str);

    /*
    *  @function my_strlen
    *
    *  @brief Return the length of a string
    *  @param str string to check
    *  @return int length
    */
    int my_strlen(char const *str);

    /*
    *  @function my_strncat
    *
    *  @brief Concatenate n characters of a string into another
    *  @param dest destination string
    *  @param src source string
    *  @param n number of characters to concatenate from the source string
    *  @return char *str
    */
    char *my_strncat(char *dest, char *src, int n);

    /*
    *  @function my_strncmp
    *
    *  @brief Compare the first n characters of two strings
    *  @param s1 first string
    *  @param s2 second string
    *  @param n number of characters to compare
    *  @return 0 if equal, else if not
    */
    int my_strncmp(char const *s1, char const *s2, int n);

    /*
    *  @function my_strncpy
    *
    *  @brief Copy n characters of a string into another
    *  @param dest destination string
    *  @param src source string
    *  @param n number of characters to copy from the source string
    *  @return char *str
    */
    char *my_strncpy(char *dest, char *src, int n);

    /*
    *  @function my_swap
    *
    *  @brief Swap two characters in a string
    *  @param a first character
    *  @param b second character
    */
    void my_swap(char *a, char *b);

    /*
    *  @function my_tablen
    *
    *  @brief Return the length of a tab
    *  @param tab tab to check
    *  @return int length
    */
    int my_tablen(char **tab);

    /*
    *  @function my_tostr
    *
    *  @brief Convert an int to a string
    *  @param nb number to convert
    *  @return char *number
    */
    char *my_tostr(int nb);

    /*
    *  @function my_wordarray
    *
    *  @brief Separate a string into an array of strings
    *  @param str string to separate
    *  @param characters characters to use as separators
    *  @return char **tab
    */
    char **my_wordarray(char *str, char *characters);

    char *my_getenv(char **my_env, char *str);
    int my_searchintab(char **tab, char *str);

#endif /* MY_H_ */
