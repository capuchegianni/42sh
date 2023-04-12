/*
** EPITECH PROJECT, 2023
** B-CPE-100-LIL-1-1-Cworkshoplib-gianni.henriques
** File description:
** my_isprime
*/

int my_isprime(int nb)
{
    int i = 2;

    if (nb < 0)
        return 0;
    while (i < nb) {
        if (nb % i == 0)
            return 0;
        else
            i++;
    }
    return 1;
}
