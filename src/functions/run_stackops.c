#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <errno.h>

int	run_stackops(char *str, t_bundle *bundle)
{
	if (ft_strcmp(str, "pa") == 0)
		pa(bundle, 0);
	else if (ft_strcmp(str, "pb") == 0)
		pb(bundle, 0);
	else if (ft_strcmp(str, "ra") == 0)
		ra(bundle, 0);
	else if (ft_strcmp(str, "rb") == 0)
		rb(bundle, 0);
	else if (ft_strcmp(str, "rr") == 0)
		rr(bundle, 0);
	else if (ft_strcmp(str, "rra") == 0)
		rra(bundle, 0);
	else if (ft_strcmp(str, "rrb") == 0)
		rrb(bundle, 0);
	else if (ft_strcmp(str, "rrr") == 0)
		rrr(bundle, 0);
	else if (ft_strcmp(str, "sa") == 0)
		sa(bundle, 0);
	else if (ft_strcmp(str, "sb") == 0)
		sb(bundle, 0);
	else if (ft_strcmp(str, "ss") == 0)
		ss(bundle, 0);
	else
		return (0);
	return (1);
}
