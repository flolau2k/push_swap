/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:10:54 by flauer            #+#    #+#             */
/*   Updated: 2023/05/04 09:11:24 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_ops(t_state *st)
{
	ft_printf("start: \n");
	ft_putstate(st);
	ft_pb(st);
	ft_putstate(st);
	ft_pa(st);
	ft_putstate(st);
	ft_ra(st);
	ft_putstate(st);
	ft_pb(st);
	ft_pb(st);
	ft_putstate(st);
	ft_rr(st);
	ft_putstate(st);
	ft_rrr(st);
	ft_putstate(st);
}
