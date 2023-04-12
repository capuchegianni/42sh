/*
** EPITECH PROJECT, 2023
** B-CPE-100-LIL-1-1-Cworkshoplib-gianni.henriques
** File description:
** my_printf
*/

#include "my.h"

void disp_stdarg(const char *s, va_list *ap, int i)
{
    if (s[i + 1] == 's')
        my_putstr(va_arg(*ap, char *));
    if (s[i + 1] == 'i' || s[i + 1] == 'd')
        my_putnbr(va_arg(*ap, int));
    if (s[i + 1] == 'c')
        my_putchar(va_arg(*ap, int));
    if (s[i + 1] == 'f')
        my_putfloat(va_arg(*ap, double));
    if (s[i + 1] == '%')
        my_putchar('%');
}

void my_printf(const char *format, ...)
{
    va_list ap;
    int n = my_strlen(format);

    va_start(ap, format);
    for (int i = 0 ; i < n ; i++) {
        if (format[i] != '%')
            my_putchar(format[i]);
        else {
            disp_stdarg(format, &ap, i);
            i++;
        }
    }
    va_end(ap);
}
