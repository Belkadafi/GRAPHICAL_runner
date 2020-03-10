/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** my_runner
*/

#include "runner.h"

int second_check_error(char *buffer)
{
    int test = 0;

    for (int i = 0; buffer[i]; i += 1) {
        if (buffer[i] != '1' && buffer[i] != '2' &&
        buffer[i] != '3' && buffer[i] != '4' &&
        buffer[i] != '4' && buffer[i] != ' ') {
            write(2, "Bad map\n", 9);
            return (1);
        }
        if (buffer[i] != ' ' && test == 1) {
            write (2, "The last obstacle must be the flags\n", 37);
            return 1;
        }
        if (buffer[i] == '4')
            test = 1;
    }
    return (0);
}

int check_error(char *filepath)
{
    FILE *stream = fopen(filepath, "r");
    char *buffer = NULL;
    char *is_finish;
    size_t len = 0;

    if (!stream) {
        write(2, "WRONG FILE\n", 12);
        return (1);
    }
    getline(&buffer, &len, stream);
    if (getline(&is_finish, &len, stream) != -1) {
        write(2, "The file must contain only one line\n", 37);
        return (1);
    }
    return (second_check_error(buffer));
}

void my_print_help(void)
{
    write (1, "Finite runner created with CSFML."
"\n      USAGE"
"\n    ./my_runner map.txt"
"\nOPTIONS"
"\n  maps are composed by '1' '2' '3' '4' and spaces"
"\n  the '1' are the spikes you have to jump over them"
"\n  the '2' are flying cars you have to slide under"
"\n  the '3' are the zombies you have to kill"
"\n  the '4' is a flags which is the end of the stage"
"\n  the '4' must be the last element of your map"
"\n  the maps are only on one line"
"\nUSER INTERACTIONS"
"\n  SPACE_KEY jump."
"\n  ESCAPE_KEY Pause."
"\n  X_KEY ATTACK"
"\n  DOWN_ARROW SLIDE\n", 494);
    return;
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        my_print_help();
    else if (ac != 2) {
        write (2, "Invalid execution\n", 19);
        return (84);
    }
    else {
        if (check_error(av[1]))
            return (84);
        game_init(av[1]);
    }
}