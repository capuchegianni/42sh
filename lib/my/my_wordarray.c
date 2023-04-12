/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** word_array
*/

#include "my.h"

int my_detectchar(char *characters, char c)
{
    for (int i = 0; characters[i]; i++) {
        if (characters[i] == c)
            return (1);
    }
    return (0);
}

int my_getwordnbr(char *str, char *characters)
{
    int words = 0;

    for (int i = 0; str[i]; i++) {
        if (my_detectchar(characters, str[i]) == 1)
            words++;
    }
    return words;
}

int remove_useless(char **tab, int k, int words, int *i)
{
    int z = *i;

    if (k == 0 && words != 0) {
        free(tab[z]);
        z--;
        *i = z;
        words--;
    }
    return (words);
}

char **separate_words(char *str, int words, char **tab, char *characters)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int chars = my_strlen(str);

    for (; i <= words; i++) {
        tab[i] = malloc(sizeof(char) * (chars + 2));
        if (tab[i] == NULL)
            return (NULL);
        for (; str[j] && my_detectchar(characters, str[j]) == 1; j++);
        for (; str[j] && my_detectchar(characters, str[j]) == 0; j++, k++)
            tab[i][k] = str[j];
        tab[i][k] = '\0';
        words = remove_useless(tab, k, words, &i);
        k = 0;
    }
    tab[i] = NULL;
    return (tab);
}

char **my_wordarray(char *str, char *characters)
{
    char *str2 = NULL;
    char **tab = NULL;
    int words = 0;

    if (tab != NULL)
        return (tab);
    str2 = my_cleanstr(str);
    if (str2 == NULL)
        return (NULL);
    words = my_getwordnbr(str2, characters);
    tab = malloc(sizeof(char *) * (words + 3));
    if (tab == NULL)
        return (NULL);
    tab = separate_words(str2, words, tab, characters);
    if (tab == NULL)
        return (NULL);
    free(str2);
    return (tab);
}
