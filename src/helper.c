/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:58:49 by flauer            #+#    #+#             */
/*   Updated: 2023/05/15 11:44:46 by flauer           ###   ########.fr       */
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

void	free_splits(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
	splits = NULL;
}
