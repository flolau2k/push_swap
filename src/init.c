/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:04:14 by flauer            #+#    #+#             */
/*   Updated: 2023/05/02 18:01:27 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	divide(int **lst, int l, int r)
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

void	find_sectors(t_state *st)
{
	int		*lst;
	t_list	*tmp;
	int		i;

	lst = malloc(sizeof(int) * ft_lstsize(st->a));
	tmp = st->a;
	i = 0;
	while (tmp)
	{
		lst[i] = content(tmp);
		++i;
		tmp = tmp->next;
	}
	pre_quicksort(&lst, 0, i - 1);
	st->low = lst[i/3];
	st->high = lst[(i/3)*2];
	st->mid = lst[i/2];
}

bool	init_stack(int argc, char *args[], t_state *st)
{
	int			i;
	int			*curr_val;
	static bool	check[UINT32_MAX];

	i = 0;
	st->a = NULL;
	st->b = NULL;
	while (i < argc)
	{
		curr_val = ft_atoi(args[i]);
		if (i == 0)
		{
			st->min = *curr_val;
			st->max = st->min;
		}
		if (!curr_val || check[(unsigned int) *curr_val])
			return (false);
		if (*curr_val < st->min)
			st->min = *curr_val;
		else if (*curr_val > st->max)
			st->max = *curr_val;
		check[(unsigned int) *curr_val] = true;
		ft_lstadd_back(&st->a, ft_lstnew(curr_val));
		++i;
	}
	find_sectors(st);
	return (true);
}

void	free_stacks(t_state *st)
{
	ft_lstclear(&st->a, &clear_elm);
	ft_lstclear(&st->b, &clear_elm);
}

bool	init(int argc, char *argv[], t_state *st)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		argc = ft_alen((const char **)args);
		return (init_stack(argc, args, st));
	}
	else
		return (init_stack(argc - 1, argv + 1, st));
}
