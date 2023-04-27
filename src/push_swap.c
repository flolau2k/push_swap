/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:55:50 by flauer            #+#    #+#             */
/*   Updated: 2023/04/27 11:45:19 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	init_stack(int argc, char *args[], t_state *st)
{
	int			i;
	int			*curr_val;
	static bool	check[UINT32_MAX];

	i = 0;
	while (i < argc)
	{
		curr_val = ft_atoi(args[i]);
		if (!curr_val || check[(unsigned int) *curr_val])
			return (false);
		check[(unsigned int) *curr_val] = true;
		ft_lstadd_back(&st->a, ft_lstnew(curr_val));
		++i;
	}
	return (true);
}

bool	init(int argc, char *argv[], t_state *st)
{
	char	**args;

	if (argc < 2)
		return (false);
	else if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		argc = ft_alen((const char **)args);
		return (init_stack(argc, args, st));
	}
	else
		return (init_stack(argc - 1, argv + 1, st));
}

int	main(int argc, char *argv[])
{
	t_state	st;

	if (!init(argc, argv, &st))
		return (write(1, "ERROR\n", 6));
	ft_putlst(st.a);
	return (0);
}
