/*
** EPITECH PROJECT, 2020
** virtual_machine.h
** File description:
** prototype for the_virtual_machine
*/

#ifndef VIRTUAL_H
#define VIRTUAL_H

//read_cor.c
void reada_file(champ_t *champ);

//tools.c
int power(int nb, int pow);
int get_type(char const *param, char *name);
int get_binary_type(char const *param);
int is_typed(int code);

//init_empty_champ.c
champ_t **init_empty_champ(void);
parser_t *init_parser_t(void);
int check_parser_values(parser_t *parser);
int fill_cor_file(char *name, parser_t *parser, champ_t *player);
int check_cor_file(char *name);
int check_value_prog(char *name, parser_t *parser);
int check_value_adress(char *name, parser_t *parser);
int check_value_dump(char *name, parser_t *parser);

#endif /* !VIRTUAL_H */
