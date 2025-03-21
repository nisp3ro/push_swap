#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../libft/include/get_next_line.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nb;
	int				mask;
	struct s_stack	*next;
}					t_stack;

//checks
void		checker_atoi(const char *str);
void		check_duplicates(t_stack *stack_a);
int			is_sorted(t_stack *stack);
void		error_exit(void);

//sorters
void		chunk_sort_to_b(t_stack **stack_a, t_stack **stack_b, int len);
void		stack_b_to_a_sorted(t_stack **stack_a, t_stack **stack_b, int len);
void		sort_5(t_stack **stack_a, t_stack **stack_b);
void		sort_4(t_stack **stack_a, t_stack **stack_b);
void		sort_3(t_stack **stack_a, int min, int next_min);

//utils
int			get_min(t_stack **stack, int val);
int			get_distance(t_stack **stack, int min);
int			find_sqr(int n);
int			count_r(t_stack *stack, int len);

//stack_management
void		stack_creator(char **argv, t_stack **stack_a, int firstarg);
void		normalice_stack(t_stack *stack_a);
t_stack		*new_stack_node(int nb);
void		stack_add_back(t_stack **lst, t_stack *new);
void		clean_stack(t_stack **lst);
t_stack		*stack_last(t_stack *lst);
int			stack_size(t_stack **lst);

//instructions
void		swap_a(t_stack **stack_a, int orderflag);
void		swap_b(t_stack **stack_b, int orderflag);
void		swap_ab(t_stack **stack_a, t_stack **stack_b, int orderflag);
void		push_a(t_stack **stack_a, t_stack **stack_b, int orderflag);
void		push_b(t_stack **stack_a, t_stack **stack_b, int orderflag);
void		rotate_a(t_stack **stack_a, int orderflag);
void		rotate_b(t_stack **stack_b, int orderflag);
void		rotate_ab(t_stack **stack_a, t_stack **stack_b, int orderflag);
void		r_rotate_a(t_stack **stack_a, int orderflag);
void		r_rotate_b(t_stack **stack_b, int orderflag);
void		r_rotate_ab(t_stack **stack_a, t_stack **stack_b, int orderflag);

#endif
