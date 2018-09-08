#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <errno.h>

void				run_stackops(char *str, t_bundle *bundle)
{
	if (ft_strcmp(str, "pa") == 0)
		pa(bundle);
	else if (ft_strcmp(str, "pb") == 0)
		pb(bundle);
	else if (ft_strcmp(str, "ra") == 0)
		ra(bundle);
	else if (ft_strcmp(str, "rb") == 0)
		rb(bundle);
	else if (ft_strcmp(str, "rr") == 0)
		rr(bundle);
	else if (ft_strcmp(str, "rra") == 0)
		rra(bundle);
	else if (ft_strcmp(str, "rrb") == 0)
		rrb(bundle);
	else if (ft_strcmp(str, "rrr") == 0)
		rrr(bundle);
	else if (ft_strcmp(str, "sa") == 0)
		sa(bundle);
	else if (ft_strcmp(str, "sb") == 0)
		sb(bundle);
	else if (ft_strcmp(str, "ss") == 0)
		ss(bundle);
	else
		throw(EXIT_FAILURE, "error1\n");
}
