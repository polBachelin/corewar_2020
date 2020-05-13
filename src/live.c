/*
** EPITECH PROJECT, 2020
** live
** File description:
** live
*/

#include

static int champ_alive(champ_t *champion, vm_t *vm)
{
    char *str;

    vm->cycle_to_die = -1;
    vm->nb_live++;
    vm->current_champ = champion;
//    write(1, "The Champion ", 10);
    str = champion->file_name;
    while (*str != '.' && *str)
        my_printf(1, "The Champion %s is alive\n", str); //avant le %s y'a un truc ?? et str ou str++ ??
//        write(1, str++, 1);
//    write(1, " is alive.\n", 11);
    return 0;
}

int live(champ_t *champion, vm_t *vm)
{
    champ_t *tmp;
    char flag;

    if (champion->/*nb de champ, max de champ*/[0] == champion->process->registre[0]
       || champion->process->registre[0])
        return (do_live(champion, vm));
    else {
        tmp = champion->process->next;
        while (tmp != champion) {
            if (champion->/*nb de champ, max de champ*/ == tmp->process->registre[0])
                do_live(tmp, vm);
            tmp = tmp->process->next;
        }
    }
    return 0;
}
/*
int main()
{
    }*/
