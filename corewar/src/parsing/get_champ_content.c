/*
** EPITECH PROJECT, 2020
** get_champ_content.c
** File description:
** get champ content from buf
*/

#include "corewar.h"

void get_prog_size(char **buf, int *prog_size)
{
    *prog_size = get_nbytes(buf, 4);
    my_printf(2, SDREDN, "prog_size = ", *prog_size);
    if (*prog_size > MEM_SIZE)
    {
        my_printf(2, "%sError Champ too big: %d > %d%s\n",
        RED, *prog_size, MEM_SIZE, DEF);
        exit(EXIT_FAILURE);
    }
}

void get_prog_name(char **buf, char name[][PROG_NAME_LENGTH])
{
    for (ssize_t i = 0; i != PROG_NAME_LENGTH; i++)
    {
        (*name)[i] = *(*buf + i);
    }
}

void get_prog_comment(char **buf, char comment[][COMMENT_LENGTH])
{
    for (ssize_t i = 0; i != COMMENT_LENGTH; i++)
    {
        (*comment)[i] = *(*buf + i);
    }
}
