/*
** EPITECH PROJECT, 2020
** structs.h
** File description:
** structs header
*/

#ifndef STRUCT_H
#define STRUCT_H

#include "op.h"

extern struct op_s op_tab[];

typedef struct {
    int  index;
    int  code;
    char *param1;
    char *param2;
    char *param3;
    char *param4;
} cmd_t;

typedef struct {
    int   index;
    char  *name;
    int   len;
    int   nb_cmd;
    cmd_t *commands;
} funct_t;

typedef struct {
    char name[PROG_NAME_LENGTH];
    char comment[COMMENT_LENGTH];
    int  magic;
    int  prog_size;
    char *file_name;
    int  fd;
    int  len;
} champion_header_t;

typedef struct process_s {
    int  id;
    int  pc;
    int  start_pos;
    int carry;
    int  cycle_length;
    int  wait_cycles;
    int  live;
    int  registre[REG_NUMBER + 1];
    struct operation_s *operation_to_do;
    struct process_s   *next;
} process_t;

typedef struct operation_s {
    int index;
    int code;
    int pcode;
    int params;
    int param_types;
    int nb_cycles;
    int (*operation)();
    struct operation_s *next;
} operation_t;

typedef struct {
    char *file_name;
    char name[PROG_NAME_LENGTH];
    char comment[COMMENT_LENGTH];
    char *prog;
    int value[MAX_ARGS_NUMBER];
    int  prog_size;
    int  champ_nb;
    int  champ_pos;
} champ_t;

typedef struct virtual_machine {
    int  cycle;
    int  total_cycle;
    int  cycle_to_die;
    int  nb_live;
    int  last_live_nb;
    char *last_name;
    int  dump_cycle;
    int  nb_champs;
    char mem[MEM_SIZE];
    champ_t champ[4];
    operation_t *ops;
    process_t   *all_process;
} vm_t;

typedef struct
{
    int nb_players;
    int nb_n;
    int nb_a;
    int last_n;
    int last_a;
    int nb_dump;
    int min_prog_number;
    int dump;
} parser_t;

#endif /* !ASSEMBLER_H_ */
