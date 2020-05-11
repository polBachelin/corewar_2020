/*
** EPITECH PROJECT, 2020
** full_cmd_len
** File description:
** gets all the cmd lens
*/

#include "corewar.h"

int get_full_cmd_len(char **str, int start_pos)
{
    int len;
    char *tmp;

    if ((tmp = get_func_name(str[start_pos])) == NULL)
        len = count_cmd_len_first(str, start_pos);
    else
        len = count_cmd_len(str, start_pos);
    if (tmp)
        free(tmp);
    return len;
}
