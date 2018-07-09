/*
** EPITECH PROJECT, 2018
** destroy.c
** File description:
** Plot table destroy function
*/

#include <stdlib.h>
#include "types.h"

plot_table_t	*destroy_plot_table_v1grate(plot_table_t *plot_table)
{
	uint_t	i = 0;

	while (i < 100) {
		plot_table->v1.grate[i] = 0;
		plot_table->v2 = 0;
		i++;
	}
	free(plot_table->v1.grate);
	plot_table->v1.grate = NULL;
	free(plot_table->v2);
	plot_table->v2 = NULL;
	free(plot_table);
	plot_table = NULL;
	return(plot_table);
}

plot_table_t	*destroy_plot_table_v1idx(plot_table_t *plot_table)
{
	uint_t	i = 0;

	while (i < 100) {
		plot_table->v1.idx[i] = 0;
		plot_table->v2 = 0;
		i++;
	}
	free(plot_table->v1.idx);
	plot_table->v1.idx = NULL;
	free(plot_table->v2);
	plot_table->v2 = NULL;
	free(plot_table);
	plot_table = NULL;
	return(plot_table);
}

plot_table_t	*destruct_plot_table(plot_table_t *plot_table)
{
	if (plot_table->type == GRATE_PARSING) {
		plot_table = destroy_plot_table_v1grate(plot_table);
	} else if (plot_table->type == INTERVAL_PARSING) {
		plot_table = destroy_plot_table_v1idx(plot_table);
	}
	return (plot_table);
}
