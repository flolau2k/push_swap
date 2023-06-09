/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:23:07 by flauer            #+#    #+#             */
/*   Updated: 2023/05/11 10:21:26 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_seclast(t_list *lst)
{
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

/// @brief (reverse rotate lst): Shift down all elements of stack a by 1.
/// The last element becomes the first one.
/// @param lst the Stack to rotate
void	_rrot(t_list **lst)
{
	t_list	*temp;

	if (!*lst || ft_lstsize(*lst) < 2)
		return ;
	temp = ft_lstlast(*lst);
	ft_seclast(*lst)->next = NULL;
	temp->next = *lst;
	*lst = temp;
}

/// @brief (reverse rotate a): Shift down all elements of stack a by 1.
/// The last element becomes the first one.
/// @param st state struct
void	ft_rra(t_state *st)
{
	_rrot(&st->a);
	ft_printf("rra\n");
}

/// @brief (reverse rotate b): Shift down all elements of stack b by 1.
/// The last element becomes the first one.
/// @param st state struct
void	ft_rrb(t_state *st)
{
	_rrot(&st->b);
	ft_printf("rrb\n");
}

/// @brief rra and rrb at the same time
/// @param st state struct
void	ft_rrr(t_state *st)
{
	_rrot(&st->a);
	_rrot(&st->b);
	ft_printf("rrr\n");
}
