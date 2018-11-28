#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

static void	print_solution(int	sol_id)
{
	if (sol_id == 1)
		ft_putstr("pa");
	else if (sol_id == 2)
		ft_putstr("pb");
	else if (sol_id == 3)
		ft_putstr("ra");
	else if (sol_id == 4)
		ft_putstr("rb");
	else if (sol_id == 5)
		ft_putstr("rr");
	else if (sol_id == 6)
		ft_putstr("rra");
	else if (sol_id == 7)
		ft_putstr("rrb");
	else if (sol_id == 8)
		ft_putstr("rrr");
	else if (sol_id == 9)
		ft_putstr("sa");
	else if (sol_id == 10)
		ft_putstr("sb");
	else if (sol_id == 11)
		ft_putstr("ss");
	else if (sol_id == 12)
		ft_putstr("--><--");
}

void	print_solutions(t_bundle *bundle)
{
	int		i;

	i = 0;
	while (i < bundle->operations_length)
	{
		print_solution(bundle->operations[i]);
		ft_putstr("\n");
		i++;
	}
}
