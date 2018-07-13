/*
** EPITECH PROJECT, 2018
** build_pop_helpers.c
** File description:
** pop_info_building helpers functions
*/

#include <stdlib.h>
#include "types.h"
#include "defs.h"

void	fill_init_pop(uint_t *init_pop, char *arg)
{
	*init_pop = atoi(arg);
}

void	fill_interval_pop(uint_t *gen_pop, char *arg, pflags_t *pflag)
{
	if (*pflag == INTERVAL_PARSING) {
		*gen_pop = ((uint_t) atoi(arg));
	}
}

void	fill_grate(double *grate, char *arg, pflags_t *pflag)
{
	if (*pflag == GRATE_PARSING) {
		*grate = atof(arg);
	}
}

int	grate_within_bounds(double *grate, pflags_t *pflag)
{
	if (*pflag == INTERVAL_PARSING) {
		return (1);
	} else if (*grate < MIN_GRATE || *grate > MAX_GRATE) {
		*pflag = ERROR;
		return (0);
	} else {
		return (1);
	}
}
