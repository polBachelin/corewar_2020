/*
** EPITECH PROJECT, 2020
** my_lfork
** File description:
** fork long
*/

#include "corewar.h"

int my_lfork(vm_t *vm, process_t *process)
{
    process_t *new;
    process_t *old = process;
    champ_t champ = get_champ_from_process(process, vm);
    int adr;
    int type = get_param_type(vm, process, 1);

    if (type != IND_SIZE)
        return -1;
    if (!(new = malloc(sizeof(process_t))))
        exit_w_msg("Failed to create new process\n", vm);
    vmemset(new, '\0', sizeof(process_t));
    copy_process(&new, old, sizeof(process_t));
    insert_process(vm, new);
    adr = get_param_value(vm, process, 1);
    new->wait_cycles = 0;
    new->operation_to_do = NULL;
    new->pc = MEME((process->pc + adr));
    new->id = champ.champ_nb;
    move_pc(vm, process);
    return 0;
}
