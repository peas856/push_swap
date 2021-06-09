/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhee <rhee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:47:01 by rhee              #+#    #+#             */
/*   Updated: 2021/06/09 19:01:59 by rhee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		quick_pushb(t_stack **a, t_stack **b, int n, int *cntpa, int *cntra)
{
	int i;
	int	L;
	int	S;

	L = (*a)->pivotL;
	S = (*a)->pivotS;
	i = 0;
	while (i < n)
	{
		if ((*b)->val >= S)
		{
			ft_push(a, b, 1);
			(*cntpa)++;
			if ((*a)->val < L)
				{
					rotate(a, 0);
					(*cntra)++;
				}
		}
		else
			rotate(b, 1);
		i++;
	}
}

void		quick_backb(t_stack **a, t_stack **b, int n, int cntpa, int cntra)
{
	int i;

	i =  -1;
	while (++i < ft_min(n - cntpa, cntra))
		rrr(a, b);
	if (n - cntpa < cntra)
	{
		while (i++ < cntra)
			rrotate(a, 0);
	}
	else
	{
		while (i++ < n - cntpa)
			rrotate(b, 1);
	}
}

void	quick_sort(t_stack **a, t_stack **b, int n)
{
	int		cntpb;
	int		cntrb;

	if (n <= 1)
		return ;
	if (n == 2)
	{
		if ((*a)->val > ((*a)->next)->val)
			ft_swap(*a, 0);
		return;
	}
	if(is_sorted(*a, n))
		return ;
	cntpb = 0;
	cntrb = 0;
	(*a)->pivotL = find_pivot(*a, n, 1);
	(*a)->pivotS = find_pivot(*a, n, 0);
	quick_push(a, b, n, &cntpb, &cntrb);
	quick_back(a, b, n, cntpb, cntrb);
	quick_sort(a, b, n-cntpb);
	quick_sortb(b, a, cntrb);
	quick_sortb(b, a, cntpb - cntrb);
}

void	quick_sortb(t_stack **b, t_stack **a, int n)
{
	int		cntpa;
	int		cntra;

	if (n <= 2)
	{
		if (n == 1)
			ft_push(a, b, 1);
		else if (n == 2)
		{
			if ((*b)->val < (*b)->next->val)
				ft_swap(*b, 1);
			ft_push(a, b, 1);
			ft_push(a, b, 1);
		}
		return ;
	}
	cntpa = 0;
	cntra = 0;
	(*a)->pivotL = find_pivot(*b, n, 1);
	(*a)->pivotS = find_pivot(*b, n, 0);
	quick_pushb(a, b, n, &cntpa, &cntra);
	quick_sort(a, b, cntpa - cntra);
	quick_backb(a, b, n, cntpa, cntra);
	quick_sort(a, b, cntra);
	quick_sortb(b, a, n - cntpa);
}