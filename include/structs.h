/*
** EPITECH PROJECT, 2018
** structs.h
** File description:
** Header file for structs declarations
*/

#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include "stypes.h"

struct	plot_table_s {
	pflags_t	type;
	union	v1_u {
		uint_t	*idx;
		double	*grate;
	} v1;
	double	*v2;
};

struct	pop_info_s {
	pflags_t	ctype;
	struct plot_table_s	*(*compute)(struct plot_table_s *, struct pop_info_s *);
	double	grate;
	uint_t	init_pop;
	uint_t	gen_x;
	uint_t	gen_y;
};

#endif
