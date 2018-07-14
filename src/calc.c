#include <stdio.h>
#include "types.h"

void	compute_from_grate(pop_info_t *pop)
{
	uint_t	i = 0;
	double	last_pop = pop->init_pop;
	double	population = 0.0;

	while (i < 100) {
		population = pop->grate * last_pop * ((1000 - last_pop) / 1000);
		printf("%u %.2f\n", (i + 1), population);
		last_pop = population;
		i++;
	}
}

void	compute_from_interval(pop_info_t *pop)
{
	uint_t	generation = 1;
	double	k = 1.00;
	double	population = 0.0;
	double	last_pop = pop->init_pop;

	while (k <= 4.00) {
		population = k * last_pop * ((1000 - last_pop) / 1000);
		if (generation >= pop->gen_x) {
			printf("%.2f %.2f\n", k, population);
		}
		generation++;
		last_pop = population;
		if (generation >= pop->gen_y) {
			k += 0.01;
			generation = 1;
			last_pop = pop->init_pop;
		}
	}
}
