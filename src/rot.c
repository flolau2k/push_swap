/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:19:17 by flauer            #+#    #+#             */
/*   Updated: 2023/05/09 16:35:29 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief (rotate lst): Shift up all elements of stack a by 1.
/// The first element becomes the last one.
/// @param lst the Stack to rotate
static void	ft_rot(t_list **lst)
{
	t_list	*temp;

	if (!*lst || ft_lstsize(*lst) < 2)
		return ;
	temp = *lst;
	*lst = temp->next;
	temp->next = NULL;
	ft_lstlast(*lst)->next = temp;
}

/// @brief (rotate a): Shift up all elements of stack a by 1.
/// The first element becomes the last one.
/// @param st state struct
void	ft_ra(t_state *st)
{
	ft_rot(&st->a);
	ft_printf("ra\n");
}

/// @brief (rotate b): Shift up all elements of stack b by 1.
/// The first element becomes the last one.
/// @param st state struct
void	ft_rb(t_state *st)
{
	ft_rot(&st->b);
	ft_printf("rb\n");
}

/// @brief ra and rb at the same time
/// @param st state struct
void	ft_rr(t_state *st)
{
	ft_rot(&st->a);
	ft_rot(&st->b);
	ft_printf("rr\n");
}
