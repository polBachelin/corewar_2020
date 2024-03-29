/*
** EPITECH PROJECT, 2020
** get_indexes.c
** File description:
** get and put indexes in the cmd structs
*/

#include "corewar.h"

static void get_param_info(cmd_t *cmd, int *value)
{
    *value += 1 + is_typed(cmd->code - 1);
    *value += get_type(cmd->param1, OTM(cmd->code - 1));
    *value += get_type(cmd->param2, OTM(cmd->code - 1));
    *value += get_type(cmd->param3, OTM(cmd->code - 1));
    *value += get_type(cmd->param4, OTM(cmd->code - 1));
}

int get_indexes(funct_t **funct)
{
    int value = 0;

    for (int i = 0; i != (*funct)[0].len; i++) {
        (*funct)[i].index = value;
        for (int j = 0; j != (*funct)[i].nb_cmd; j++) {
            (*funct)[i].commands[j].index = value;
            get_param_info(&(*funct)[i].commands[j], &value);
        }
    }
    return value;
}
