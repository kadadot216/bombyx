#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include "stypes.h"

struct	pop_info_s {
	pflags_t	ctype;
	void	(*compute)(struct pop_info_s *);
	double	grate;
	uint_t	init_pop;
	uint_t	gen_x;
	uint_t	gen_y;
};

#endif
