/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:10:18 by flauer            #+#    #+#             */
/*   Updated: 2023/05/09 17:49:44 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list *dst, t_list *src)
{
	t_list	*temp;

	if (ft_lstsize(src) < 1)
		return ;
	temp = src;
	src = src->next;
	ft_lstadd_front(&dst, temp);
}

void	ft_pa(t_state *st)
{
	ft_push(st->a, st->b);
	ft_printf("pa\n");
}

void	ft_pb(t_state *st)
{
	ft_push(st->b, st->a);
	ft_printf("pb\n");
}
