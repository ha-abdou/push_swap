#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

static void set_mins(t_numlist *numlist, int min_value, int min_index)
{
	t_numlist	*tmp;
	t_numlist	*min_elm;

	tmp = numlist;
	while (tmp && tmp->value <= min_value && tmp->index != 0)
		tmp = tmp->next;
	if (!(min_elm = tmp))
		return ;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->value < min_elm->value && tmp->index == 0)
			min_elm = tmp;
		tmp = tmp->next;
	}
	min_elm->index = min_index + 1;

	set_mins(numlist,  min_elm->value, min_elm->index);
}

static void	create_index(t_numlist *numlist)
{
	t_numlist	*tmp;
	int			min;
	int			min_index;

	tmp = numlist;
	min_index = 1;
	tmp->index = 1;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
		{
			numlist->index = 0;
			min = tmp->value;
			tmp->index = min_index;
		}
		tmp = tmp->next;
	}
	set_mins(numlist, min, min_index);
}

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
	{
		numlist = create_numlist_elm(tab[0]);
		free(tab[0]);
	}
	else
		throw(0, "Error\n");
	while (tab[i])
	{
		numlist_push(numlist, create_numlist_elm(tab[i]));
		free(tab[i]);
		i++;
	}
	free(tab);
	create_index(numlist);
	return (numlist);
}
