#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct 		s_stack	
{
	int				val;
	struct s_stack	*next;
	int				pivotL;
	int				pivotS;
	int				len;
}					t_stack;

typedef struct		s_stk
{
	t_stack			*a;
	t_stack			*b;	
}					t_stk;
//check_arg.c
int			is_number(char *s);
void		check_duplicates(t_stack *a);
int			ft_atoi2(const char *str);
void		disp_stack(t_stk arg);
int			ft_cnt(char **s);

//command.c
void		ft_swap(t_stack *stk, int n);
void		rotate(t_stack **stk, int n);
void		rrotate(t_stack **stk, int n);
void		rrr(t_stack **a, t_stack **b);
int			push(t_stack **stk, int val);

//main.c
void		destroy_stack(t_stack **stk);
int			stack_size(t_stack *stk);
void		ft_exit(void);

//quick_sub.c
int			is_sorted(t_stack *a, int len);
int			find_pivot(t_stack *a, int len, int op);
int			ft_min(int a, int b);
void		quick_push(t_stack **a, t_stack **b, int n, int *cntpb, int *cntrb);
void		quick_back(t_stack **a, t_stack **b, int n, int cntpb, int cntrb);


//quick.c
void		quick_pushb(t_stack **a, t_stack **b, int n, int *cntpa, int *cntra);
void		quick_backb(t_stack **a, t_stack **b, int n, int cntpa, int cntra);
void		quick_sort(t_stack **a, t_stack **b, int n);
void		quick_sortb(t_stack **b, t_stack **a, int n);

//stack.c

t_stack		*pop(t_stack **stack);
t_stack		*new_node(int val);
int			ft_push(t_stack **to, t_stack **from, int op);
void		is_val(t_stack **stk, char *s);
t_stack		*make_stack(int ac, char **av);

#endif