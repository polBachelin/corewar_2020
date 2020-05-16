/*
** EPITECH PROJECT, 2020
** print_mem
** File description:
** prints the vm memory
*/

#include "corewar.h"

static const int DISP_SIZE = 64;

void show_champ(vm_t *vm, int i, int len, int nb)
{
    unsigned char byte;

    for (; i < len; i++) {
        byte = vm->mem[i];
        (nb == 1) ? my_printf(2, SXRED " ", F16(byte)) : 0;
        (nb == 2) ? my_printf(2, SXBLUE " ", F16(byte)) : 0;
        (nb == 3) ? my_printf(2, SXGREEN " ", F16(byte)) : 0;
        (nb == 4) ? my_printf(2, SXYELLOW " ", F16(byte)) : 0;
    }
}

void print_pcs(vm_t *vm, UNSD champ_t *champ, int i, int nb)
{
    unsigned char byte = vm->mem[i];
    process_t *p = vm->all_process;

    while (p) {
        if (p->pc == i) {
            (nb == 1) ? my_printf(2, SXWHITE " ", F16(byte), byte) : 0;
            (nb == 2) ? my_printf(2, SXRED " ", F16(byte), byte) : 0;
            (nb == 3) ? my_printf(2, SXBLUE " ", F16(byte), byte) : 0;
            (nb == 4) ? my_printf(2, SXGREEN " ", F16(byte), byte) : 0;
        }
        p = p->next;
    }
}


void print_mem(vm_t *vm)
{
    unsigned char byte;

    for (int i = 0; i < MEM_SIZE; i++) {
        byte = vm->mem[i];
        if (i == vm->all_process->pc)
            my_printf(2, FBG SXRED " ", F16(byte), byte);
        else if (i > vm->champ->prog_size)
            my_printf(2, DARK SXWHITE " ", F16(byte), byte);
        else
            my_printf(2, SXRED " ", F16(byte), byte);
        if (!((i + DISP_SIZE + 1) % DISP_SIZE))
            my_printf(2, "\n");
    }
}

/*
void print_mem(vm_t *vm)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i == vm->champ->champ_pos) {
            print_pcs(vm, vm->champ, i, vm->champ->champ_nb);
            show_champ(vm, i, vm->champ->prog_size, vm->champ->champ_nb);
        }
        my_printf(2, SXLBLACK " ", (vm->mem[i] < 16) ? "0" : "", vm->mem[i]);
        if (!((i + DISP_SIZE + 1) % DISP_SIZE))
            my_printf(2, "\n");
    }
}
*/
