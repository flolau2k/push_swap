/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:14:18 by flauer            #+#    #+#             */
/*   Updated: 2023/05/11 09:43:29 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_swap(t_list **lst)
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
	_swap(&st->a);
	ft_printf("sa\n");
}

void	ft_sb(t_state *st)
{
	_swap(&st->b);
	ft_printf("sb\n");
}

void	ft_ss(t_state *st)
{
	_swap(&st->a);
	_swap(&st->b);
	ft_printf("ss\n");
}
