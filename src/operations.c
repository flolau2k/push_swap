/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:36:43 by flauer            #+#    #+#             */
/*   Updated: 2023/05/04 12:03:02 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_op(t_state *st, int op)
{
	if (op == SA)
		return (ft_sa(st));
	else if (op == SB)
		return (ft_sb(st));
	else if (op == PA)
		return (ft_pa(st));
	else if (op == PB)
		return (ft_pb(st));
	else if (op == RA)
		return (ft_ra(st));
	else if (op == RB)
		return (ft_rb(st));
	else if (op == RRA)
		return (ft_rra(st));
	else if (op == RRB)
		return (ft_rrb(st));
}

void	do_op(t_state *st, int op)
{
	static int	op_cache;

	if (op == FLSH)
		return (handle_op(st, op_cache));
	else if ((op_cache == SA && op == SB) || (op_cache == SB && op == SA))
		return (op_cache = 0, ft_ss(st));
	else if ((op_cache == RA && op == RB) || (op_cache == RB && op == RA))
		return (op_cache = 0, ft_rr(st));
	else if ((op_cache == RRA && op == RRB) || (op_cache == RRB && op == RRA))
		return (op_cache = 0, ft_rrr(st));
	else if (op_cache)
		return (op_cache = op, handle_op(st, op_cache));
	op_cache = op;
}
