#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

t_numlist	*create_numlist_elm(char *str)
{
	t_numlist	*elm;
	int			i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			throw(0, "error\n");
		i++;
	}
	elm = (t_numlist *)malloc(sizeof(t_numlist));
	elm->value = ft_atoi(str);
	elm->next = 0;
	elm->index = 0;
	return (elm);
}
