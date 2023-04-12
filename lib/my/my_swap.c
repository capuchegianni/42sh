/*
** EPITECH PROJECT, 2023
** B-CPE-100-LIL-1-1-Cworkshoplib-gianni.henriques
** File description:
** my_swap
*/

void my_swap(char *a, char *b)
{
    int rev;
    rev = *a;
    *a = *b;
    *b = rev;
}
