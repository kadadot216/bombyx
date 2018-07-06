/*
** EPITECH PROJECT, 2018
** calc.c
** File description:
** Calculations related functions
*/

#include <math.h>
#include "types.h"

void	compute_from_grate(plot_table_t *plot_table, pop_info_t *pop)
{
	uint_t	i = 0;

	while (i < 100) {
		if (i == 0) {
			plot_table[i] = pop->init_pop;
		} else {
			plot_table[i] = pop->grate * plot_table[i-1] * ((1000 - plot_table[i-1]) / 1000);
		}
		i++;
	}
}

void	compute_from_interval(plot_table_t *plot_table, pop_info_t *pop)
{

}

void	compute_plot_table(double *plot_table, pop_info_t *pop)
{
	if (*pop->comp == GRATE_PARSING) {
		compute_from_grate(plot_table, pop);
	} else if (*pop->comp == INTERVAL_PARSING) {
		compute_from_interval(plot_table, pop);
	}
}
