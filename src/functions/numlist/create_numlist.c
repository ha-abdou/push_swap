#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

t_numlist	*create_numlist(const char *str)
{
	t_numlist	*numlist;
	char		**tab;
	int			i;

	if (!str)
		return (0);
	i = 1;
	tab = ft_strsplit(str, ' ');
	if (tab[0])
		numlist = create_numlist_elm(tab[0]);
	while (tab[i])
	{
		numlist_push(numlist, create_numlist_elm(tab[i]), 0);
		i++;
	}
	return (numlist);
}
