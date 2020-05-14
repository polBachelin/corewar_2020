/*
** EPITECH PROJECT, 2020
** move_pc
** File description:
** moves the pc
*/

#include "corewar.h"

void move_pc(vm_t *vm, process_t *process)
{
    int tmp_pc = 0;//get_next_pc(vm, process);
    int new_pos = tmp_pc + process->pc;

    if (new_pos > MEM_SIZE)
        new_pos %= MEM_SIZE;
    process->pc = new_pos;
}