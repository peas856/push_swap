#include "push_swap.h"

void	destroy_stack(t_stack **stk)
{
	t_stack	*tmp;

	while (*stk)
	{
		tmp = *stk;
		*stk = (*stk)->next;
		free(tmp);
		tmp = NULL;
	}
}

int		stack_size(t_stack *stk)
{
	int		size;

	size = 0;
	while (stk)
	{
		size++;
		stk = stk->next;
	}
	return (size);
}

void	ft_exit(void)
{
	write(1, "Error\n",6);
	exit(0);
}

void	ft_sort(t_stack **a)
{
	int f;
	int m;
	int l;

	f = (*a)->val;
	m = (*a)->next->val;
	l = (*a)->next->next->val;

	if (f < m && m < l)
		return ;
	else if (f < l && l < m)
	{
		rrotate(a, 0);
		ft_swap(*a, 0);
	}
	else if (l < f && l > m)
		rotate(a, 0);
	else if (f > m && m > l)
	{
		ft_swap(*a, 0);
		rrotate(a, 0);
	}
	else if (f > m && m < l)
		ft_swap(*a, 0);
	else if (f < m && m > l)
		rrotate(a, 0);
	return ;
}

int		main(int ac, char **av)
{
	t_stk	stk;

	if (ac == 1)
		return (0);
	stk.a = make_stack(ac, av);
	if (!stk.a)
	 	ft_exit();
	check_duplicates(stk.a);
	stk.b = NULL;
	// disp_stack(stk);
	if (stack_size(stk.a) == 3)
		ft_sort(&stk.a);
	quick_sort(&stk.a, &stk.b, stack_size(stk.a));
	// disp_stack(stk);
	destroy_stack(&stk.a);
	destroy_stack(&stk.b);
	return (0);
}