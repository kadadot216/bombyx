#include "types.h"
#include "my.h"

static void	check_for_helpflag(pflags_t *pflag, char *curr_arg)
{
		if (my_strcmp(curr_arg, "-h") == 0) {
			*pflag = HELP;
		}
}

static void	arg_is_number(pflags_t *pflag, char *curr_arg)
{
	if (!my_str_isnum(curr_arg) || curr_arg[0] == '-') {
		*pflag = ERROR;
	}
}

static pflags_t	check_for_valid_args(pflags_t pflag, int *ac, char **av)
{
	int	i = 0;

	while (i < *ac && pflag != HELP && pflag != ERROR) {
		check_for_helpflag(&pflag, av[i]);
		if (pflag == HELP) {
			return (pflag);
		}
		arg_is_number(&pflag, av[i]);
		i++;
	}
	return (pflag);
}

static void	check_ac_and_set(pflags_t *f, int *ac, int nb, pflags_t tgt)
{
	if (*ac == nb) {
		*f = tgt;
	}
}

pflags_t	build_pflagsmask(int ac, char **av)
{
	pflags_t	pflag = 0;

	if (ac == 0) {
		return (WARNING);
	}
	check_ac_and_set(&pflag, &ac, 2, GRATE_PARSING);
	check_ac_and_set(&pflag, &ac, 3, INTERVAL_PARSING);
	pflag = check_for_valid_args(pflag, &ac, av);
	if (pflag == 0) {
		return (ERROR);
	}
	return (pflag);
}
