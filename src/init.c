/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:04:14 by flauer            #+#    #+#             */
/*   Updated: 2023/05/17 10:36:18 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	presort(t_state *st)
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
	free(lst);
}

static bool	check_arg(char *arg)
{
	int	i;

	if (!arg)
		return (false);
	if (arg[0] != '+' && arg[0] != '-' && !ft_isdigit(arg[0]))
		return (false);
	i = 1;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (false);
		if (i > 11)
			return (false);
		++i;
	}
	return (true);
}

bool	check_dup(int val)
{
	static size_t	c;

	if (c & (1 << (unsigned int)val))
		return (true);
	c |= 1 << (unsigned int)val;
	return (false);
}

bool	init_stack(int argc, char *args[], t_state *st)
{
	int				i;
	t_elm			*curr_elm;
	long long		new;

	i = 0;
	st->a = NULL;
	st->b = NULL;
	curr_elm = NULL;
	while (i < argc)
	{
		if (!check_arg(args[i]))
			return (clear_lists(st), false);
		new = ft_atoi(args[i]);
		if (new > INT32_MAX || new < INT32_MIN || check_dup(new))
			return (clear_lists(st), false);
		curr_elm = new_elm(new);
		if (!curr_elm)
			return (clear_lists(st), false);
		ft_lstadd_back(&st->a, ft_lstnew(curr_elm));
		++i;
	}
	st->len = argc;
	return (true);
}

int	ft_alen(const char **a)
{
	int	i;

	i = 0;
	while (a[i])
		++i;
	return (i);
}

bool	init(int argc, char *argv[], t_state *st)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		argc = ft_alen((const char **)args);
		if (!init_stack(argc, args, st))
			return (free_splits(args), false);
		free_splits(args);
		presort(st);
		return (true);
	}
	else
	{
		if (!init_stack(argc - 1, argv + 1, st))
			return (false);
		presort(st);
		return (true);
	}
}
