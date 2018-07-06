/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** printing related functions
*/

#include <stdio.h>
#include "my.h"
#include "defs.h"
#include "types.h"

void	print_usage(char *pname)
{
	my_putstr("USAGE\n"
		"\t\t");
	my_putstr(pname);
	my_putstr(" n [	k | i0 i1]\n\n"
		"DESCRIPTION\n"
		"\tn\tnumber of first generation individuals\n"
		"\tk\tgrowth rate from 1 to 4\n"
		"\ti0\tinitial generation (included)\n"
		"\ti1\tfinal generation (included)\n");
}

int	my_exit_usage(char *pname, pflags_t pflag)
{
	if (pflag == ERROR) {
		my_puterror("Wrong usage of arguments!\n");
	}
	print_usage(pname);
	if (pflag & HELP || pflag & WARNING) {
		return (MY_EXIT_SUCCESS);
	} else {
		return (MY_EXIT_FAILURE);
	}
}

void	display_plot_table(plot_table_t *plot_table)
{
	uint_t	i = 0;

	while (i < 100) {
		printf("%u %.2f\n", (i + 1), plot_table[i]);
		i++;
	}
}
