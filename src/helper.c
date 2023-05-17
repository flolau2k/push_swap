/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:58:49 by flauer            #+#    #+#             */
/*   Updated: 2023/05/17 11:22:33 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(t_list *lst, t_list *elm)
{
	int		ret;
	t_list	*curr_elm;

	ret = 0;
	curr_elm = lst;
	while (curr_elm && get_id(curr_elm) != get_id(elm))
	{
		curr_elm = curr_elm->next;
		++ret;
	}
	return (opt_rot(lst, ret));
}

int	get_pos_id(t_list *lst, int id)
{
	int		ret;
	t_list	*curr_elm;

	ret = 0;
	curr_elm = lst;
	while (curr_elm && get_id(curr_elm) != id)
	{
		curr_elm = curr_elm->next;
		++ret;
	}
	return (opt_rot(lst, ret));
}

int	opt_rot(t_list *lst, int i)
{
	int	len;

	len = ft_lstsize(lst);
	if (i <= len / 2)
		return (i);
	else
		return (i - len);
}

size_t	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

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
