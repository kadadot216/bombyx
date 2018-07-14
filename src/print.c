#include <stdio.h>
#include "my.h"
#include "defs.h"
#include "types.h"

void	print_usage(char *pname)
{
	my_putstr("USAGE\n"
		"\t\t");
	my_putstr(pname);
	my_putstr(" n [k | i0 i1]\n\n"
		"DESCRIPTION\n"
		"\tn\tnumber of first generation individuals\n"
		"\tk\tgrowth rate from 1 to 4\n"
		"\ti0\tinitial generation (included)\n"
		"\ti1\tfinal generation (included)\n");
}

int	my_exit_usage(char *pname, pflags_t pflag)
{
	print_usage(pname);
	if (pflag & HELP) {
		return (MY_EXIT_SUCCESS);
	} else {
		return (MY_EXIT_FAILURE);
	}
}
