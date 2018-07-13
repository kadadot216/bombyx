/*
** EPITECH PROJECT, 2018
** calc.c
** File description:
** Calculations related functions
*/

#include <math.h>
#include <stdlib.h>
#include "types.h"

#include <stdio.h>

plot_table_t	*init_plot_table(plot_table_t *plot_table, pop_info_t *pop)
{
	uint_t	size = 0;

	plot_table = malloc(sizeof(plot_table_t));
	plot_table->type = pop->ctype;
	if (plot_table->type == INTERVAL_PARSING) {
		size = ((pop->gen_y - pop->gen_x) * 300);
		plot_table->v1.grate = malloc(sizeof(double) * size);
	} else if  (plot_table->type == GRATE_PARSING) {
		size = 100;
		plot_table->v1.idx = malloc(sizeof(uint_t) * size);
	}
	plot_table->v2 = malloc(sizeof(double) * size);
	
	return (plot_table);
}

plot_table_t	*compute_from_grate(plot_table_t *plot_table, pop_info_t *pop)
{
	uint_t	i = 0;

	while (i < 100) {
		if (i == 0) {
			plot_table->v2[i] = (double) pop->init_pop;
		} else {
			plot_table->v2[i] = pop->grate * plot_table->v2[i-1] *
				((1000 - plot_table->v2[i-1]) / 1000);
		}
		plot_table->v1.idx[i] = (i + 1);
		i++;
	}
	return (plot_table);
}

plot_table_t	*compute_from_interval(plot_table_t *plot_table, pop_info_t *pop)
{
	uint_t	generation = 1;
	uint_t	idx = 0;
	double	k = 1.00;
	double	population = 0.0;
	double	last_pop = pop->init_pop;

	while (k <= 4.00) {
		population = k * last_pop * ((1000 - last_pop) / 1000);
		if (generation >= pop->gen_x) {
			plot_table->v1.grate[idx] = k;
			plot_table->v2[idx] = population;
			idx++;
		}
		generation++;
		last_pop = population;
		if (generation >= pop->gen_y) {
			k += 0.01;
			generation = 1;
			last_pop = pop->init_pop;
		}
	}
	return (plot_table);
}
