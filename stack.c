#include "push_swap.h"

t_stack	*new_node(int val)
{
	t_stack	*node;

	if (!(node = (t_stack *) malloc(sizeof(t_stack))))
		return (0);
	node->val = val;
	node->next = NULL;
	node->pivotL = 0;
	node->pivotS = 0;
	return (node);
}

t_stack	*pop(t_stack **stack)
{
	t_stack *tmp;

	tmp = NULL;
	if (!*stack)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	return (tmp);
}

int		ft_push(t_stack **to, t_stack **from, int op)
{
	t_stack	*node;
	t_stack *new;
	int		val;

	node = pop(from);
	val = node->val;
	free(node);
	if (!*to)
	{
		if (!(*to = new_node(val)))
			return (0);
	}
	else
	{
		if (!(new = new_node(val)))
			return (0);
		new->next = *to;
		*to = new;
	}
	if (op == 0)
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
	return (1);
}

void	is_val(t_stack **stk, char *s)
{
	if (!is_number(s))
		ft_exit();
	if (!push(stk, ft_atoi2(s)))
		exit(1);
}

t_stack	*make_stack(int ac, char **av)
{
	t_stack	*stack;
	char **s;
	int		i;

	s = NULL;
	stack = NULL;
	i = 0;
	while (--ac > 0)
	{
		s = ft_split(av[ac], ' ');
		i = ft_cnt(s);
		if(i)
		{
			while(*s)
				s++;
			while (i-- > 0)
			{
				s--;
				is_val(&stack, *s);
			}
		}
		else
			is_val(&stack, av[ac]);
	}
	return (stack);
}