/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:22:43 by flauer            #+#    #+#             */
/*   Updated: 2023/05/04 13:45:13 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO negative numbers!
// Optimize ... 
void	ft_radix(t_state *st)
{
	t_sort	sort;

	sort.factor = 1;
	sort.len = ft_lstsize(st->a);
	// sort.max = ft_max(st->a);
	while (!sorted(st) && sort.factor <= sort.len)
	{
		sort.i = 0;
		while(sort.i < sort.len)
		{
			if (!((id(st->a) / sort.factor) % 2))
			{
				do_op(st, PB);
			}
			else
				do_op(st, RA);
			++sort.i;
		}
		while(st->b)
		{
			do_op(st, PA);
		}
		sort.factor *= 2;
	}
}
