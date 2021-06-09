/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhee <rhee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:47:01 by rhee              #+#    #+#             */
/*   Updated: 2021/06/09 18:50:25 by rhee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_sorted(t_stack *a, int len)
{
	while(--len)
	{
		if (a->val > a->next->val)
			return (0);
		a = a->next;
	}
	return (1);
}
int			find_pivot(t_stack *a, int len, int op)
{
	int check;
	t_stack	*node;
	t_stack	*tmp;
	int		cnt;
	int		i;
	int		j;

	cnt = 0;
	j = len;
	if (op == 0)
		check = len / 3;
	else
		check = (len * 2) / 3;
	tmp = a;
	while (len--)
	{
		node = tmp;
		cnt = 0;
		i = j;
		while (i--)
		{
			if(a->val > node->val)
				cnt++;
			node = node->next;
		}
		if (cnt == check)
			return (a->val);
		a = a->next;
	}
	return (a->val);
}

int				ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void		quick_push(t_stack **a, t_stack **b, int n, int *cntpb, int *cntrb)
{
	int i;
	int	L;
	int	S;

	L = (*a)->pivotL;
	S = (*a)->pivotS;
	i = 0;
	while (i < n)
	{
		if ((*a)->val < L)
		{
			ft_push(b, a, 0);
			(*cntpb)++;
			if ((*b)->val > S)
				{
					rotate(b, 1);
					(*cntrb)++;
				}
		}
		else
			rotate(a, 0);
		i++;
	}
}

void		quick_back(t_stack **a, t_stack **b, int n, int cntpb, int cntrb)
{
	int i;

	i =  -1;
	while (++i < ft_min(n - cntpb, cntrb))
		rrr(a, b);
	if ((n-cntpb) < cntrb)
	{
		while (i++ < cntrb)
			rrotate(b, 1);
	}
	else
	{
		while (i++ < n - cntpb)
			rrotate(a, 0);
	}
}

// void	quick_sort(t_stack **a, t_stack **b, int n)
// {
// 	int		cntpb;
// 	int		cntrb;
// 	int		pivotS;
// 	int		pivotL;
// 	int		i;

// 	if (n <= 1)
// 		return ;
// 	if (n == 2)
// 	{
// 		if ((*a)->val > ((*a)->next)->val)
// 			ft_swap(*a, 0);
// 		return;
// 	}
// 	if(is_sorted(*a, n))
// 		return ;
// 	cntpb = 0;
// 	cntrb = 0;
// 	pivotL = find_pivot(*a, n, 1);
// 	pivotS = find_pivot(*a, n, 0);
// 	i = 0;
// 	while (i < n)
// 	{
// 		if ((*a)->val < pivotL)
// 		{
// 			ft_push(b, a, 0);
// 			cntpb++;
// 			if ((*b)->val > pivotS)
// 				{
// 					rotate(b, 1);
// 					cntrb++;
// 				}
// 		}
// 		else
// 			rotate(a, 0);
// 		i++;
// 	}
// 	i =  -1;
// 	while (++i < ft_min(n - cntpb, cntrb))
// 		rrr(a, b);
// 	if ((n-cntpb) < cntrb)
// 	{
// 		while (i++ < cntrb)
// 			rrotate(b, 1);
// 	}
// 	else
// 	{
// 		while (i++ < n - cntpb)
// 			rrotate(a, 0);
// 	}
// 	quick_sort(a, b, n-cntpb);
// 	quick_sortb(b, a, cntrb);
// 	quick_sortb(b, a, cntpb - cntrb);
// }

// void	quick_sortb(t_stack **b, t_stack **a, int n)
// {
// 	int		toplen;
// 	double	pivotS;
// 	double	pivotL;
// 	int		i;
// 	int		cntra;

// 	if (!(*b) || n <= 0)
// 		return ;
// 	if (n == 1)
// 	{
// 		ft_push(a, b, 1);
// 		return ;
// 	}
// 	else if (n == 2)
// 	{
// 		if ((*b)->val < (*b)->next->val)
// 			ft_swap(*b, 1);
// 		ft_push(a, b, 1);
// 		ft_push(a, b, 1);
// 		return ;
// 	}
// 	toplen = 0;
// 	cntra = 0;
// 	pivotL = find_pivot(*b, n, 1);
// 	pivotS = find_pivot(*b, n, 0);
// 	i = 0;
// 	while (i < n)
// 	{
// 		if ((*b)->val >= pivotS)
// 		{
// 			ft_push(a, b, 1);
// 			toplen++;
// 			if ((*a)->val < pivotL)
// 				{
// 					rotate(a, 0);
// 					cntra++;
// 				}
// 		}
// 		else
// 			rotate(b, 1);
// 		i++;
// 	}
// 	quick_sort(a, b, toplen - cntra);
// 	i =  -1;
// 	while (++i < ft_min(n - toplen, cntra))
// 		rrr(a, b);
// 	if (n - toplen < cntra)
// 	{
// 		while (i++ < cntra)
// 			rrotate(a, 0);
// 	}
// 	else
// 	{
// 		while (i++ < n - toplen)
// 			rrotate(b, 1);
// 	}
// 	quick_sort(a, b, cntra);
// 	quick_sortb(b, a, n - toplen);
// }