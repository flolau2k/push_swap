/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:23:07 by flauer            #+#    #+#             */
/*   Updated: 2023/04/28 14:01:19 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_seclast(t_list *lst)
{
	while (lst->next->next)
		lst = lst->next;
	return lst;
}

void	ft_rra(t_state *st)
{
	t_list *temp;

	temp = ft_lstlast(st->a);
	ft_seclast(st->a)->next = NULL;
	temp->next = st->a;
	st->a = temp;
	ft_printf("rra\n");
}

void	ft_rrb(t_state *st)
{
	t_list *temp;

	temp = ft_lstlast(st->b);
	ft_seclast(st->b)->next = NULL;
	temp->next = st->b;
	st->b = temp;
	ft_printf("rrb\n");
}

void	ft_rrr(t_state *st)
{
	ft_rra(st);
	ft_rrb(st);
}
