#include "libft.h"
#include "push_swap.h"

void	print_pivots(int *pivots, char *msg)
{
	int		i;

	i = 0;
	ft_putstr(GRN);
	ft_putstr(msg);
	while (pivots[i])
	{
		ft_putnbr(i);
		ft_putstr(":");
		ft_putnbr(pivots[i]);
		ft_putstr("\n");
		i++;
	}
	ft_putstr(RESET);
}
