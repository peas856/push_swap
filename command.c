#include "push_swap.h"

void	ft_swap(t_stack *stk, int n)
{
	t_stack	*top;
	t_stack	*second;
	int		tmp;

	second = stk;
	top = stk->next;	
	if (!second || !top)
		return ;
	tmp = second->val;
	second->val = top->val;
	top->val = tmp;
	if (n == 0)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	rotate(t_stack **stk, int n)
{
	t_stack	*bottom;
	t_stack	*top;

	if (!(*stk)->next)
		return ;
	bottom = *stk;
	top = (*stk)->next;
	while ((*stk)->next)
		*stk = (*stk)->next;
	(*stk)->next = bottom;
	bottom->next = NULL;
	*stk = top;
	if (n == 0)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rrotate(t_stack **stk, int n)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack *last;

	if (!(*stk)->next)
		return ;
	tmp = *stk;
	last = *stk;
	while (tmp->next)
	{
		if (!tmp->next->next)
			last = tmp;
		tmp = tmp->next;	
	}
	first = tmp;
	first->next = *stk;
	last->next = NULL;
	*stk = first;
	if (n == 0)
		write(1, "rra\n", 4);
	else if (n == 1)
		write(1, "rrb\n", 4);
	else 
		return ;
}

void	rrr(t_stack **a, t_stack **b)
{
	rrotate(a, 2);
	rrotate(b, 2);
	write(1, "rrr\n", 4);
}

int		push(t_stack **stk, int val) //*stack 자리로 삽입하는 것 
{
	t_stack *new;
	
	if (!*stk)
	{
		if (!(*stk = new_node(val)))
			return (0);
	}
	else
	{
		if (!(new = new_node(val)))
			return (0);
		new->next = *stk;
		*stk = new;
	}
	return (1);
}