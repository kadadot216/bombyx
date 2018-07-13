/*
** EPITECH PROJECT, 2018
** prototypes.h
** File description:
** Header file for function prototypes
*/

#ifndef __PROTOTYPES_H__
#define __PROTOTYPES_H__

#include "types.h"

int	fill_pop_info(pop_info_t *pop, pflags_t *pflag, char **av);
void	empty_pop_info(pop_info_t *pop);
void	compute_plot_table(double *plot_table, pop_info_t *pop);
plot_table_t	*init_plot_table(plot_table_t *plot_table, pop_info_t *pop);
plot_table_t	*destruct_plot_table(plot_table_t *plot_table,
	pop_info_t *pop);

#endif
