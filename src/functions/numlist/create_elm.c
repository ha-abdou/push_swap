#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static int	check_int_overflow(int num, const char *str)
{
	int		i;

	i = num % 10;
	if (i < 0)
	{
		i *= -1;
		if (str[0] != '-')
			return (1);
	}
	if (i - (str[ft_strlen(str) - 1] - '0') != 0)
		return (1);
	return (0);
}

static void	rm_mem(t_bundle *bundle, t_numlist *numlist)
{
	if (numlist)
		free_numlist(numlist);
	free(bundle);
	throw(0, "Error\n");
}

t_numlist	*create_numlist_elm(t_bundle *bundle, t_numlist *numlist,\
const char *str)
{
	t_numlist	*elm;
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] == '-' && !ft_isdigit(str[i + 1]))
			rm_mem(bundle, numlist);
		i++;
	}
	if (!(elm = (t_numlist *)malloc(sizeof(t_numlist))))
		throw(0, "Error\n");
	elm->value = ft_atoi(str);
	elm->next = 0;
	elm->index = 0;
	if (check_int_overflow(elm->value, str))
	{
		free(elm);
		rm_mem(bundle, numlist);
	}
	return (elm);
}
