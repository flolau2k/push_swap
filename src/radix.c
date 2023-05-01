/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:22:43 by flauer            #+#    #+#             */
/*   Updated: 2023/05/01 11:32:15 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO negative numbers!
// Optimize ... 
#include <stdio.h>
void	ft_radix(t_state *st)
{
	t_sort	sort;

	sort.factor = 1;
	sort.len = ft_lstsize(st->a);
	sort.max = ft_max(st->a);
	while (!ft_sorted(st) && sort.factor <= sort.max)
	{
		sort.i = 0;
		while(sort.i < sort.len)
		{
			if (!((ft_cont(st->a) / sort.factor) % 2))
			{
				ft_pb(st);
				// ft_rb(st);
			}
			else
				ft_ra(st);
			++sort.i;
		}
		while(st->b)
		{
			ft_pa(st);
			//ft_ra(st);
		}
		sort.factor *= 2;
	}
}
