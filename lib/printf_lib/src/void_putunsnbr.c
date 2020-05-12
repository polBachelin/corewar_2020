/*
** EPITECH PROJECT, 2019
** my_putunsnbr.c
** File description:
** put_unsigned_number
*/

#include "my_printf.h"

long if_unsneg(long nb)
{
    long nb_temp = nb;

    if (nb == 0)
        write(1, "0", 1);
    if (nb < 0)
    {
        nb_temp = nb_temp * (-1);
        write(1, "-", 1);
    }
    return (nb_temp);
}

void void_putunsnbr(int output, unsigned int nb)
{
    unsigned int counter = 1000000000;
    unsigned int count_temp = 0;
    long nb_2 = nb;
    long nb_temp = if_unsneg(nb_2);
    char c;

    nb_2 = nb_temp;
    while (counter != 0) {
        while (nb_2 >= counter) {
            nb_2 = nb_2 - counter;
            count_temp++;
        }
        if (nb_temp - counter >= 0) {
            c = count_temp + 48;
            write(output, &c, 1);
        }
        counter = counter / 10;
        count_temp = 0;
    }
}