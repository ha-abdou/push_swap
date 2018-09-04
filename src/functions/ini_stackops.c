#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
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
/*
static void			push(char *name, (*func)(void *bundle))
{

}
*/
static t_stackops	*new(char *name, void (*func)(void *bundle))
{
	t_stackops	*elm;

	elm = (t_stackops*)malloc(sizeof(elm));
	ft_strcpy(elm->name, name);
	elm->func = func;
	elm->next = 0;
	return (elm);
}

void				run_stackops(char *str, t_bundle *bundle)
{
	if (ft_strcmp(str, "pb") == 0)
		pb(bundle);
	else
		throw(EXIT_FAILURE, "error\n");
}

void				ini_stackops(t_bundle *bundle)
{
	t_stackops	*list;

	list = new("pb", &pb);
	bundle->opfunctions = list;
//	push(list, new("pa", &pb));
/*
	ft_strcpy(bundle->opfunctions[0].name, "pb");
	bundle->opfunctions[0].func = &pb;
	ft_strcpy(bundle->opfunctions[1].name, "pa");
	bundle->opfunctions[1].func = &pb;*/
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