#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static void set_mins(t_numlist *numlist, t_numlist *min)
{
	t_numlist	*tmp;
	t_numlist	*tmp_min;

	tmp_min = min;
	tmp = numlist;
	while (tmp && tmp->value <= min->value && tmp->index != 0)
		tmp = tmp->next;
	if (!(min = tmp))
		return ;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->value < min->value && tmp->index == 0)
			min = tmp;
		tmp = tmp->next;
	}
	min->index = tmp_min->index + 1;
	set_mins(numlist, min);
}

static void	create_index(t_numlist *numlist)
{
	t_numlist	*tmp;
	t_numlist	*min;

	min = numlist;
	min->index = 1;
	tmp = numlist->next;
	while (tmp)
	{
		if (tmp->value < min->value)
		{
			min->index = 0;
			min = tmp;
			min->index = 1;
		}
		tmp = tmp->next;
	}
	set_mins(numlist, min);
}

t_numlist	*create_numlist(t_bundle *bundle, const char **str, int len)
{
	t_numlist	*numlist;
	int			i;

	i = 2;
	numlist = 0;
	numlist = create_numlist_elm(bundle, numlist, str[1]);
	while (i < len)
	{
		numlist_push(bundle, numlist,\
			create_numlist_elm(bundle, numlist, str[i]));
		i++;
	}
	create_index(numlist);
	return (numlist);
}
