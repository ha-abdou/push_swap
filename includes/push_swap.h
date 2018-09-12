#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define OPS_BUUFER_LENGTH 5000

typedef struct s_numlist
{
	int					value;
	int					index;
	struct s_numlist	*next;
} t_numlist;

typedef struct s_bundle
{
	void		(*apply_function)(struct s_bundle *bundle, char *str);
	int			(*is_sorted)(struct s_bundle *bundle);
	int			*operations;
	int			operations_length;
	t_numlist	*list_a;
	int			list_a_length;
	t_numlist	*list_b;
	int			list_b_length;
} t_bundle;

t_bundle	*create_bundle(const char *str);
int			is_sorted(struct s_bundle *bundle);
void		throw(int code, char *msg);
t_numlist	*create_numlist(const char *str);
t_numlist	*create_numlist_elm(char *str);
void		numlist_push(t_numlist *list, t_numlist *elm);
void		print_numlist(t_numlist *list);
void		print_numlist_index(t_numlist *list);
void		debug_bundle(t_bundle *bundle);
void		run_stackops(char *str, t_bundle *bundle);
void		print_solutions(t_bundle *bundle);
void		free_bundle(t_bundle *bundle);
void		simple_sort(t_bundle *bundle);
int			is_numlist_sorted(t_numlist *list);
void		pa(t_bundle *self, int save);
void		pb(t_bundle *self, int save);
void		ra(t_bundle *self, int save);
void		rb(t_bundle *self, int save);
void		rr(t_bundle *self, int save);
void		rra(t_bundle *self, int save);
void		rrb(t_bundle *self, int save);
void		rrr(t_bundle *self, int save);
void		sa(t_bundle *self, int save);
void		sb(t_bundle *self, int save);
void		ss(t_bundle *self, int save);
#endif
