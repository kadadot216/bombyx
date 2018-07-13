/*
** EPITECH PROJECT, 2018
** build_pop.c
** File description:
** Build population struct from args
*/

#include <stdlib.h>
#include "types.h"
#include "build_pop_helpers.h"
#include "calc.h"

compute_t	set_compute_fct(pflags_t *pflag)
{
	if (*pflag == INTERVAL_PARSING) {
		return (&compute_from_interval);
	} else if (*pflag == GRATE_PARSING) {
		return (&compute_from_grate);
	} else {
		return (NULL);
	}
}

int	fill_pop_info(pop_info_t *pop, pflags_t *pflag, char **av)
{
	pop->ctype = *pflag;
	pop->compute = set_compute_fct(&pop->ctype);
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
