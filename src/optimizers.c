/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:58:33 by flauer            #+#    #+#             */
/*   Updated: 2023/05/09 12:41:56 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_pa(t_state *st)
{
	int		cheapest;
	t_list	*ret;
	t_list	*curr_elm;

	cheapest = nsteps(st->b);
	ret = st->b;
	curr_elm = st->b;
	while (curr_elm)
	{
		if (nsteps(curr_elm) >= 0 && nsteps(curr_elm) < cheapest)
		{
			cheapest = nsteps(curr_elm);
			ret = curr_elm;
		}
		curr_elm = curr_elm->next;
	}
	rot_for_pa(st, ret);
}

void	find_min_pb(t_state *st)
{
	int		cheapest;
	t_list	*ret;
	t_list	*curr_elm;

	cheapest = nsteps(st->a);
	ret = st->a;
	curr_elm = st->a;
	while (curr_elm)
	{
		if (nsteps(curr_elm) >= 0 && nsteps(curr_elm) < cheapest)
		{
			cheapest = nsteps(curr_elm);
			ret = curr_elm;
		}
		curr_elm = curr_elm->next;
	}
	rot_for_pb(st, ret);
}

size_t	get_steps_combined(int nra, int nrb)
{
	if ((nra >= 0 && nrb >= 0) || (nra < 0 && nrb < 0))
	{
		if (ft_abs(nra) > ft_abs(nrb))
			return (ft_abs(nra));
		else
			return (ft_abs(nrb));
	}
	else
		return (ft_abs(nra) + ft_abs(nrb));
}

void	get_pb_steps(t_state *st)
{
	t_list	*curr_elm;
	int		nra;
	int		nrb;
	int		nsteps;

	curr_elm = st->a;
	while (curr_elm)
	{
		nrb = get_chunk_pos(st, curr_elm);
		nra = get_pos(st->a, curr_elm);
		nsteps = get_steps_combined(nra, nrb);
		if (get_id(curr_elm) == 0 || get_id(curr_elm) == st->len - 1)
			nsteps = INT32_MAX;
		((t_elm *)curr_elm->content)->nsteps = nsteps;
		curr_elm = curr_elm->next;
	}
}

void	get_pa_steps(t_state *st)
{
	t_list	*curr_elm;
	int		nra;
	int		nrb;
	int		nsteps;

	curr_elm = st->b;
	while (curr_elm)
	{
		nrb = get_pos(st->b, curr_elm);
		nra = _ft_ins(st->a, curr_elm);
		nsteps = get_steps_combined(nra, nrb);
		((t_elm *)curr_elm->content)->nsteps = nsteps;
		curr_elm = curr_elm->next;
	}
}
