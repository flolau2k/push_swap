/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:04:14 by flauer            #+#    #+#             */
/*   Updated: 2023/05/08 13:19:56 by flauer           ###   ########.fr       */
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

void add_id(t_list *a, int val, int id)
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

void fill_ids(t_state *st, int **lst)
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
	fill_ids(st, &lst);
	st->num_chunks = 3;
}

t_elm	*new_elm(int *content)
{
	t_elm	*ret;

	ret = malloc(sizeof(t_elm));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->id = 0;
	ret->nsteps = 0;
	return ret;
}

bool	init_stack(int argc, char *args[], t_state *st)
{
	int			i;
	t_elm		*curr_elm;
	static bool	check[UINT32_MAX];

	i = 0;
	st->a = NULL;
	st->b = NULL;
	while (i < argc)
	{
		curr_elm = new_elm(ft_atoi(args[i]));
		if (!curr_elm || check[(unsigned int) *curr_elm->content])
			return (false);
		check[(unsigned int) *curr_elm->content] = true;
		ft_lstadd_back(&st->a, ft_lstnew(curr_elm));
		++i;
	}
	st->len = argc;
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
