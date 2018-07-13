/*
** EPITECH PROJECT, 2018
** calc.c
** File description:
** Calculations related functions
*/

#include <math.h>
#include <stdlib.h>
#include "types.h"

plot_table_t	*init_plot_table(plot_table_t *plot_table, pop_info_t *pop)
{
	plot_table = malloc(sizeof(plot_table_t));
	plot_table->type = pop->ctype;
	if (plot_table->type == INTERVAL_PARSING) {
		plot_table->v1.grate = malloc(sizeof(double) * 100);
	} else if  (plot_table->type == GRATE_PARSING) {
		plot_table->v1.idx = malloc(sizeof(uint_t) * 100);
	}
	plot_table->v2 = malloc(sizeof(double) * 100);
	return (plot_table);
}

void	compute_from_grate(plot_table_t *plot_table, pop_info_t *pop)
{
	uint_t	i = 0;

	while (i < 100) {
		if (i == 0) {
			plot_table->v2[i] = pop->init_pop;
		} else {
			plot_table->v2[i] = pop->grate * plot_table->v2[i-1] *
				((1000 - plot_table->v2[i-1]) / 1000);
		}
		plot_table->v1.idx[i] = (i + 1);
		i++;
	}
}

void	compute_from_interval(plot_table_t *plot_table, pop_info_t *pop)
{
	uint_t	i = 1;
	uint_t	idx = 0;
	double	k = 1.0;
	double	value = 0.0;

	while (k <= 4.0) {
		value = pop->gen_x + i;
		while (i <= (pop->gen_y - pop->gen_x + 1)) {
			plot_table->v1.grate[idx] = k;
			plot_table->v2[idx] = value;
			idx++;
			i++;

		}
		k += 0.01;
		i = 1;
	}
}
