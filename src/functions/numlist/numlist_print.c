#include "libft.h"
#include "push_swap.h"

void	print_numlist(t_numlist *list)
{
	if (!list)
		return ;
	ft_putnbr(list->value);
	ft_putstr(" ");
	if (list->next)
		print_numlist(list->next);
}
