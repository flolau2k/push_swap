/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:29:51 by flauer            #+#    #+#             */
/*   Updated: 2023/05/09 16:35:32 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_rot_combined(t_state *st, int nra, int nrb)
{
	while (nra > 0 && nrb > 0)
	{
		ft_rr(st);
		--nra;
		--nrb;
	}
	if (nra > 0)
		ft_rotn(st, nra, 'a');
	if (nrb > 0)
		ft_rotn(st, nrb, 'b');
	while (nra < 0 && nrb < 0)
	{
		ft_rrr(st);
		++nra;
		++nrb;
	}
	if (nra < 0)
		ft_rrotn(st, -nra, 'a');
	if (nrb < 0)
		ft_rrotn(st, -nrb, 'b');
}

void	rot_for_pb(t_state *st, t_list *elm)
{
	int	nra;
	int	nrb;

	nra = get_pos(st->a, elm);
	nrb = get_chunk_pos(st, elm);
	_rot_combined(st, nra, nrb);
}

void	rot_for_pa(t_state *st, t_list *elm)
{
	int	nra;
	int	nrb;

	nrb = get_pos(st->b, elm);
	nra = _ft_ins(st->a, elm);
	_rot_combined(st, nra, nrb);
}

void	ft_rrotn(t_state *st, int n, char lst)
{
	if (lst == 'a')
	{
		while (n-- > 0)
			ft_rra(st);
	}
	else
	{
		while (n-- > 0)
			ft_rrb(st);
	}
}

void	ft_rotn(t_state *st, int n, char lst)
{
	if (lst == 'a')
	{
		while (n-- > 0)
			ft_ra(st);
	}
	else
	{
		while (n-- > 0)
			ft_rb(st);
	}
}
