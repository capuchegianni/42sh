/*
** EPITECH PROJECT, 2022
** lib-epitech
** File description:
** my_compute_power_rec
*/

int my_pow(int nb, int p)
{
    if (p < 0)
        return 84;
    if (p == 0)
        return 1;
    else
        return nb * my_pow(nb, p - 1);
}
