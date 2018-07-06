/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file for 106bombyx
*/

#include "my.h"
#include "print.h"
#include "defs.h"
#include "types.h"
#include "pflags.h"

int	main(int ac, char **av)
{
	pflags_t	pflag = 0;

	pflag = build_pflagsmask((ac - 1), &av[1]);
	if (pflag & HELP || pflag & WARNING || pflag & ERROR) {
		return (my_exit_usage(av[0], pflag));
	}
	return (MY_EXIT_FAILURE);
}
