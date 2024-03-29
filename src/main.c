#include "my.h"
#include "print.h"
#include "defs.h"
#include "types.h"
#include "pflags.h"
#include "prototypes.h"

int	main(int ac, char **av)
{
	pflags_t	pflag = 0;
	pop_info_t		pop_info;

	empty_pop_info(&pop_info);
	pflag = build_pflagsmask((ac - 1), &av[1]);
	if (pflag & HELP || pflag & WARNING || pflag & ERROR) {
		return (my_exit_usage(av[0], pflag));
	}
	if (!fill_pop_info(&pop_info, &pflag, av)) {
		empty_pop_info(&pop_info);
		return (my_exit_usage(av[0], pflag));
	}
	pop_info.compute(&pop_info);
	empty_pop_info(&pop_info);
	return (MY_EXIT_SUCCESS);
}
