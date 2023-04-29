/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:23:07 by flauer            #+#    #+#             */
/*   Updated: 2023/04/29 11:38:22 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_seclast(t_list *lst)
{
	while (lst->next->next)
		lst = lst->next;
	return lst;
}

static void	ft_rrot(t_list **lst)
{
	t_list *temp;

	temp = ft_lstlast(*lst);
	ft_seclast(*lst)->next = NULL;
	temp->next = *lst;
	*lst = temp;
}

void	ft_rra(t_state *st)
{
	ft_rrot(&st->a);
	ft_printf("rra\n");
}

void	ft_rrb(t_state *st)
{
	ft_rrot(&st->b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_state *st)
{
	ft_rrot(&st->a);
	ft_rrot(&st->b);
	ft_printf("rrr\n");
}
