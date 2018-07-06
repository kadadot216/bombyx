/*
** EPITECH PROJECT, 2018
** build_pop.c
** File description:
** Build population struct from args
*/

#include "types.h"
#include "build_pop_helpers.h"
#include "calc.h"

void	get_compute_function(compute_t *popfun, pflags_t *pflag)
{
	if (*pflag == INTERVAL_PARSING) {
		*popfun = &compute_from_interval;
	} else if  (*pflag == GRATE_PARSING) {
		*popfun = &compute_from_interval;
	}
}

int	fill_pop_info(pop_info_t *pop, pflags_t *pflag, char **av)
{
	get_compute_function(&pop->compute, pflag);
	fill_init_pop(&pop->init_pop, av[1]);
	fill_interval_pop(&pop->gen_x, av[2], pflag);
	fill_interval_pop(&pop->gen_y, av[3], pflag);
	fill_grate(&pop->grate, av[2], pflag);
	return (grate_within_bounds(&pop->grate, pflag));
}

void	empty_pop_info(pop_info_t *pop)
{
	pop->compute = 0;
	pop->init_pop = 0;
	pop->grate = 0.0;
	pop->gen_x = 0;
	pop->gen_y = 0;
}
