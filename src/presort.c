/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:42:34 by flauer            #+#    #+#             */
/*   Updated: 2023/05/09 10:50:08 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	divide(int **lst, int l, int r)
{
	int	i;
	int	j;
	int	pivot;

	i = l;
	j = r - 1;
	pivot = (*lst)[r];
	while (i < j)
	{
		while (i < j && (*lst)[i] <= pivot)
			++i;
		while (j > i && (*lst)[j] > pivot)
			--j;
		if ((*lst)[i] > (*lst)[j])
			ft_swap(*lst + i, *lst + j);
	}
	if ((*lst)[i] > pivot)
		ft_swap(*lst + i, *lst + r);
	else
		i = r;
	return (i);
}

void	pre_quicksort(int **lst, int l, int r)
{
	int	pivot;

	if (l < r)
	{
		pivot = divide(lst, l, r);
		pre_quicksort(lst, l, pivot - 1);
		pre_quicksort(lst, pivot + 1, r);
	}
}


static void	add_id(t_list *a, int val, int id)
{
	while (a)
	{
		if (content(a) == val)
		{
			((t_elm *)a->content)->id = id;
			break ;
		}
		a = a->next;
	}
}

void	fill_ids(t_state *st, int **lst)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lstsize(st->a);
	while (i < len)
	{
		add_id(st->a, (*lst)[i], i);
		++i;
	}
}
