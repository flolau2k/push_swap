/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:04:14 by flauer            #+#    #+#             */
/*   Updated: 2023/05/09 13:56:36 by flauer           ###   ########.fr       */
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
	st->num_chunks = 3;
}

static bool	init_stack(int argc, char *args[], t_state *st)
{
	int			i;
	t_elm		*curr_elm;
	static bool	check[UINT32_MAX];
	long		new;

	i = 0;
	st->a = NULL;
	st->b = NULL;
	while (i < argc)
	{
		if (ft_strlen(args[i]) > 11)
			return (false);
		new = ft_atoi(args[i]);
		if (new > INT32_MAX || new < INT32_MIN)
			return (false);
		curr_elm = new_elm(new);
		if (!curr_elm || check[(unsigned int) curr_elm->content])
			return (false);
		check[(unsigned int) curr_elm->content] = true;
		ft_lstadd_back(&st->a, ft_lstnew(curr_elm));
		++i;
	}
	st->len = argc;
	presort(st);
	return (true);
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
