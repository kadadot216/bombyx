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
	my_putstr(" n [ k | i0 i1]\n\n"
		"DESCRIPTION\n"
		"\tn\tnumber of first generation individuals\n"
		"\tk\tgrowth rate from 1 to 4\n"
		"\ti0\tinitial generation (included)\n"
		"\ti1\tfinal generation (included)\n");
}

int	my_exit_usage(char *pname, pflags_t pflag)
{
	print_usage(pname);
	if (pflag & HELP || pflag & WARNING) {
		return (MY_EXIT_SUCCESS);
	} else {
		return (MY_EXIT_FAILURE);
	}
}

void	display_plot_table(plot_table_t *plot_table, pop_info_t *pop)
{
	uint_t	i = 0;
	uint_t	max = 0;

	if (plot_table->type == GRATE_PARSING) {
		while (i < 100) {
			printf("%u %.2f\n", plot_table->v1.idx[i], plot_table->v2[i]);
			i++;
		}
	} else if (plot_table->type == INTERVAL_PARSING) {
		max = ((pop->gen_y - pop->gen_x) * 300);
		while (i < max) {
			printf("%.2f %.2f\n", plot_table->v1.grate[i], plot_table->v2[i]);
			i++;
		}
	}
}
