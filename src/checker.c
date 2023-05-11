/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:23:52 by flauer            #+#    #+#             */
/*   Updated: 2023/05/11 10:13:59 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	handle_op(t_state *st, char *op)
{
	if (!ft_strncmp(op, "sa\n", 3))
		return (_swap(&st->a), true);
	else if (!ft_strncmp(op, "sb\n", 3))
		return (_swap(&st->b), true);
	else if (!ft_strncmp(op, "ss\n", 3))
		return (_swap(&st->a), _swap(&st->b), true);
	else if (!ft_strncmp(op, "pa\n", 3))
		return (_push(&st->a, &st->b), true);
	else if (!ft_strncmp(op, "pb\n", 3))
		return (_push(&st->b, &st->a), true);
	else if (!ft_strncmp(op, "ra\n", 3))
		return (_rot(&st->a), true);
	else if (!ft_strncmp(op, "rb\n", 3))
		return (_rot(&st->b), true);
	else if (!ft_strncmp(op, "rr\n", 3))
		return (_rot(&st->a), _rot(&st->b), true);
	else if (!ft_strncmp(op, "rra\n", 3))
		return (_rrot(&st->a), true);
	else if (!ft_strncmp(op, "rrb\n", 3))
		return (_rrot(&st->b), true);
	else if (!ft_strncmp(op, "rrr\n", 3))
		return (_rrot(&st->a), _rrot(&st->b), true);
	return (false);
}

static bool	init_bonus(int argc, char *argv[], t_state *st)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		argc = ft_alen((const char **)args);
		if (!init_stack(argc, args, st))
			return (false);
		return (true);
	}
	else
	{
		if (!init_stack(argc - 1, argv + 1, st))
			return (false);
		return (true);
	}
}

int	main(int argc, char *argv[])
{
	t_state	st;
	char	*nl;

	if (argc < 2)
		return (0);
	if (!init_bonus(argc, argv, &st))
		return (write(STDERR_FILENO, "Error\n", 6));
	nl = get_next_line(STDIN_FILENO);
	while (nl)
	{
		if (!handle_op(&st, nl))
			return (write(STDERR_FILENO, "Error\n", 6));
		nl = get_next_line(STDIN_FILENO);
	}
	if (sorted(&st))
		return (ft_printf("OK\n"));
	else
		return (ft_printf("KO\n"));
}
