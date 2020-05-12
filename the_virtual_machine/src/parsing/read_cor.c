/*
** EPITECH PROJECT, 2020
** read_cor.c
** File description:
** read .cor file
*/

#include "corewar.h"

static bool decrypt_name(unsigned char value)
{
    int  code  = value;
    char *name = OTM(code - 1);
    int  typed = is_typed(code - 1);

    my_printf(2, "%s%s%s%s | ", BOLD, WHITE, name, DEF);
    my_printf(2, "%s%s%s\n", MAGENTA, typed ? "true" : "false", DEF);
    if (typed)
        return true;
    return false;
}

static int check_direct(char *name)
{
    if (!my_strcmp(name, "zjmp") && !my_strcmp(name, "ldi") &&
        !my_strcmp(name, "fork") && !my_strcmp(name, "sti") &&
        !my_strcmp(name, "lfork") && !my_strcmp(name, "lldi"))
        return DIR_SIZE;
    return IND_SIZE;
}

static void decrypt_type(unsigned char value, int params[][4], int code, bool typed)
{
    int type = value;
    int temp = 0;

    if (!typed)
    {
        (*params)[0] = check_direct(OTM(code - 1));
        return;
    }
    my_printf(2, "%stype = %d%s\n", YELLOW, type, DEF);
    for (ssize_t i = 0; i != 4; i++)
    {
        temp = type >> (2 * i);
        temp &= 0x03;
        if (temp == 2)
            (*params)[3 - i] = check_direct(OTM(code - 1));
        else
            (*params)[3 - i] = temp;
    }
}

static int read_nbytes(char **buf, int nb, int code)
{
    int result = **buf;
    unsigned char live = **buf;

    for (ssize_t i = 1; i != nb; i++)
    {
        if (!my_strcmp(OTM(code - 1), "live"))
        {
            result <<= i * 8;
            result += *(*buf + i);
            result %= power(2, 8);
        } else
        {
            live <<= i * 8;
            live += *(*buf + i);
            live %= power(2, 8);
        }
    }
    if (!my_strcmp(OTM(code - 1), "live"))
        return result;
    return live;
}

static void decrypt_params(int byte, char **buf, int *read_len, unsigned char code)
{
    unsigned char value;
    int result;
    char *temp = *buf + 1;

    if (byte == 1)
        my_printf(2, "%sREG%s  ", RED, DEF);
    else if (byte == 2)
        my_printf(2, "%sDIR%s  ", RED, DEF);
    else
        my_printf(2, "%sIND%s  ", RED, DEF);
    my_printf(2, "%ssize: %s%d  %s", GREEN, BOLD, byte, DEF);
    result = read_nbytes(&temp, byte, code);
    my_printf(2, "%s%d  %s", LBLUE, result, DEF);
    for (ssize_t i = 0; i != byte; i++)
    {
        (*read_len)--;
        (*buf)++;
        value = **buf;
        my_printf(2, "%s0%d  %s", BLUE, value, DEF);
    }
    my_printf(2, "\n");
}

static void decrypt_instruction(unsigned char code, char **buf, int *read_len)
{
    int params[4] = {0};
    bool typed = false;

    if (decrypt_name(code))
    {
        (*read_len)--;
        (*buf)++;
        typed = true;
    }
    decrypt_type(**buf, &params, code, typed);
    my_printf(2, "%sparams━━━━━━━━━━━━━━━━━━━%s\n", LGREEN, DEF);
    for (ssize_t i = 0; params[i]; i++)
        decrypt_params(params[i], buf, read_len, code);
}

static void get_prog_size(char **buf, int *prog_size)
{
    *prog_size = read_nbytes(buf, 4, 1);
    my_printf(2, "%sprog_size = %d%s\n", LRED, *prog_size, DEF);
}

static void display_values(char *buf, int read_len)
{
    int move = 0;
    int prog_size = 0;

    while (read_len--)
    {
        if (read_len < prog_size)
        {
            my_printf(2, "%s━━━━━━━━━━━%s\n", TEAL, DEF);
            my_printf(2, "%scode = %d | %sindex = %d%s\n",
                      LTEAL, *buf, LMAGENTA, prog_size - read_len - 1, DEF);
            decrypt_instruction(*buf, &buf, &read_len);
        } else if (move == 8 + PROG_NAME_LENGTH)
        {
            get_prog_size(&buf, &prog_size);
        }
        move++;
        buf++;
    }
}

static int opena_file(char *filepath)
{
    int fd;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
    {
        my_printf(2, "%sError with open : '%s'%s\n", RED, filepath, DEF);
        exit(EXIT_FAILURE);
    }
    return fd;
}

char *reada_file(char *filepath)
{
    ssize_t read_len;
    char    buf[100000];
    int     fd = opena_file(filepath);

    read_len = read(fd, &buf, 100000);
    if (read_len == (-1))
    {
        my_printf(2, "%sError with read : '%s'%s\n", RED, filepath, DEF);
        exit(EXIT_FAILURE);
    }
    display_values(buf, read_len);
    return NULL;
}
