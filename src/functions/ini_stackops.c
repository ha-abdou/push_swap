#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
/*
static t_stackops	*make_stackop(char *name, void (*func)(void *bundle))
{
	t_stackops	*tmp;

	tmp = (t_stackops*)malloc(sizeof(tmp));
	ft_strcpy(tmp->name, name);
	tmp->func = &pa;
	return (tmp);
}
*/
void	ini_stackops(t_bundle *bundle)
{
	ft_strcpy(bundle->opfunctions[0].name, "pb");
	bundle->opfunctions[0].func = &pb;
	ft_strcpy(bundle->opfunctions[1].name, "pa");
	bundle->opfunctions[1].func = &pb;
/*
	bundle->opfunctions[0].name = 
	t_stackops	*stackops;

	stackops = (t_stackops *)malloc(sizeof(t_stackops) * 11);
	ft_strcpy(stackops[0].name, "pb");
	stackops[0].func = &pb;
	ft_strcpy(stackops[1].name, "pa");
	stackops[1].func = &pb;
	return (stackops);*/
}