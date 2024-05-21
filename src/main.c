/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main
*/

#include "../include/my.h"
#include "../include/rpg.h"

int main(int argc, char **argv)
{
    rpg_t rpg;
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return helperprint(&rpg);
    if (argc != 1)
        return 84;
    main_manage(init_manage(&rpg));
    clean_all(&rpg);
    return 0;
}
