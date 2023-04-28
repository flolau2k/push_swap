/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:10:18 by flauer            #+#    #+#             */
/*   Updated: 2023/04/28 13:22:19 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_state *st)
{
	t_list	*temp;

	if (ft_lstsize(st->b) > 1)
		return ;
	temp = st->b;
	st->b = st->b->next;
	ft_lstadd_front(&st->a, temp);
}

void	ft_pb(t_state *st)
{
	t_list	*temp;

	if (ft_lstsize(st->a) > 1)
		return ;
	temp = st->a;
	st->a = st->a->next;
	ft_lstadd_front(&st->b, temp);
}

void	ft_ra(t_state *st)
{
	t_list *temp;

	temp = st->a;
	st->a = temp->next;
	temp->next = NULL;
	ft_lstlast(st->a)->next = temp;
}

void	ft_rb(t_state *st)
{
	t_list *temp;

	temp = st->b;
	st->b = temp->next;
	temp->next = NULL;
	ft_lstlast(st->b)->next = temp;
}

void	ft_rr(t_state *st)
{
	ft_ra(st);
	ft_rb(st);
}
