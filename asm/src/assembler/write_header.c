/*
** EPITECH PROJECT, 2020
** write_header
** File description:
** writes the champ header
*/

#include "corewar.h"

void write_char(char c, int fd)
{
    write(fd, &c, 1);
}

void write_header(champion_header_t *champ)
{
    int zero = 0;

    nwrite(champ->fd, &champ->magic, 4);
    for (int i = 0; champ->name[i]; i++)
        write_char(champ->name[i], champ->fd);
    for (int i = my_strlen(champ->name); i < PROG_NAME_LENGTH; i++)
        write_char(0, champ->fd);
    nwrite(champ->fd, &zero, 4);
    nwrite(champ->fd, &champ->prog_size, 4);
    for (int i = 0; champ->comment[i]; i++)
        write_char(champ->comment[i], champ->fd);
    for (int i = my_strlen(champ->comment); i < COMMENT_LENGTH + 4; i++)
        write_char(0, champ->fd);
    if (champ->len <= 2) {
        close(champ->fd);
        exit(0);
    }
}
