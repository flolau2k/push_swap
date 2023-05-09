/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:56:28 by flauer            #+#    #+#             */
/*   Updated: 2023/05/09 16:35:12 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief find the insert position for the element src into list dst at the 
/// correct location. expect dst to be sorted already, but may be rotated.
/// also dst must already contain its smallest and largest element.
/// @param dst destination list
/// @param src source element
/// @return position to insert; number of rotate operations respectively. 
/// if return is < 0, reverse rotation is needed, else normal rotation.
int	_ft_ins(t_list *dst, t_list *src)
{
	t_list	*tmp;
	int		i;

	tmp = dst;
	i = 0;
	if (get_id(dst) > get_id(src) && get_id(ft_lstlast(dst)) < get_id(src))
		return (i);
	while (tmp->next)
	{
		++i;
		if (get_id(tmp) < get_id(src) && get_id(tmp->next) > get_id(src))
			break ;
		tmp = tmp->next;
	}
	return (opt_rot(dst, i));
}
