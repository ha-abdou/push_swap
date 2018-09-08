#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

static int	check_int_overflow(int num, char *str)
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

t_numlist	*create_numlist_elm(char *str)
{
	t_numlist	*elm;
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] == '-' && !ft_isdigit(str[i + 1]))
			throw(0, "error2\n");
		i++;
	}
	if (!(elm = (t_numlist *)malloc(sizeof(t_numlist))))
		throw(0, "error3\n");
	elm->value = ft_atoi(str);
	if (check_int_overflow(elm->value, str))
		throw(0, "error4\n");
	elm->next = 0;
	elm->index = 0;
	return (elm);
}
