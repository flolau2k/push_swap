/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:19:17 by flauer            #+#    #+#             */
/*   Updated: 2023/04/29 11:36:22 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rot(t_list **lst)
{
	t_list *temp;

	temp = *lst;
	*lst = temp->next;
	temp->next = NULL;
	ft_lstlast(*lst)->next = temp;
}

void	ft_ra(t_state *st)
{
	ft_rot(&st->a);
	ft_printf("ra\n");
}

void	ft_rb(t_state *st)
{
	ft_rot(&st->b);
	ft_printf("rb\n");
}

void	ft_rr(t_state *st)
{
	ft_rot(&st->a);
	ft_rot(&st->b);
	ft_printf("rr\n");
}
