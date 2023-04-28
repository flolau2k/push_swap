/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:14:18 by flauer            #+#    #+#             */
/*   Updated: 2023/04/28 14:03:07 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_list **lst)
{
	t_list	*temp;

	if (ft_lstsize(*lst) < 2)
		return ;
	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = (*lst);
	*lst = temp;
}

void	ft_sa(t_state *st)
{
	ft_swap(&st->a);
	ft_printf("sa\n");
}

void	ft_sb(t_state *st)
{
	ft_swap(&st->b);
	ft_printf("sb\n");
}

void	ft_ss(t_state *st)
{
	ft_swap(&st->a);
	ft_swap(&st->b);
}
