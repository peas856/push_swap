#include "push_swap.h"

int		is_number(char *s)
{
	while (*s)
	{
		if (*s == '-' || *s == '+' || (*s >= '0' && *s <= '9'))
			s++;
		else
			return (0);
	}
	return (1);
}

void		check_duplicates(t_stack *a)
{
	t_stack		*slow;
	t_stack		*fast;

	slow = a;
	while (slow)
	{
		fast = slow->next;
		while (fast)
		{
			if (slow->val == fast->val)
				ft_exit();
			fast = fast->next;
		}
		slow = slow->next;
	}
}

void	disp_stack(t_stk arg)
{
	t_stack	*a;
	t_stack	*b;

	printf("\n");
	a = arg.a;
	b = arg.b;
	while (a || b)
	{
		if (a && b)
			printf("|%11d|\t\t|%11d|\n", a->val, b->val);
		else if (a)
			printf("|%11d|\t\t|%11s|\n", a->val, " ");
		else if (b)
			printf("|%11s|\t\t|%11d|\n", " ", b->val);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
}

int					ft_atoi2(const char *str)
{
	long long		i;
	long long		ret;
	int				sign;

	i = 0;
	sign = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		if (ret > 2147483647 && sign == 1)
			ft_exit();
		if (ret > 2147483648 && sign == -1)
			ft_exit();
		i++;
	}
	return (ret * sign);
}

int		ft_cnt(char **s)
{
	int i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}