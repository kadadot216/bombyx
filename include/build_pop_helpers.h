/*
** EPITECH PROJECT, 2018
** build_pop_helpers.h
** File description:
** Header file for build_pop_helpers.c
*/

#ifndef __BUILD_POP_HELPERS_H__
#define __BUILD_POP_HELPERS_H__

#include "types.h"

void	fill_init_pop(uint_t *init_pop, char *arg);
void	fill_interval_pop(uint_t *gen_pop, char *arg, pflags_t *pflag);
void	fill_grate(double *grate, char *arg, pflags_t *pflag);
int	grate_within_bounds(double *grate, pflags_t *pflag);

#endif
