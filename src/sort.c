/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:40:07 by flauer            #+#    #+#             */
/*   Updated: 2023/05/11 10:32:18 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotated(t_list	*lst)
{
	int		c;
	t_list	*tmp;
	t_list	*next;
	int		i;
	int		ret;

	c = 0;
	i = 0;
	tmp = lst;
	while (++i && tmp)
	{
		next = tmp->next;
		if (!next)
			next = lst;
		if (content(tmp) > content(next))
		{
			++c;
			ret = i;
		}
		tmp = tmp->next;
	}
	if (c == 1)
		return (ret);
	return (-1);
}

void	ft_rotate(t_state *st)
{
	int		len;
	t_list	*lst;
	int		pos;

	if (sorted(st))
		return ;
	lst = st->a;
	len = ft_lstsize(lst);
	pos = rotated(st->a);
	if (pos == -1)
		ft_printf("rot error\n");
	if (pos > len / 2)
		ft_rrotn(st, len - pos, 'a');
	else
		ft_rotn(st, pos, 'a');
}

void	ft_sort3(t_state *st)
{
	if (rotated(st->a) >= 0)
		return ;
	else
		ft_sa(st);
}

void	ft_sortn(t_state *st)
{
	if (sorted(st))
		return ;
	if (ft_lstsize(st->b) == 0 && rotated(st->a) >= 0)
		return (ft_rotate(st));
	while (ft_lstsize(st->a) > 3)
	{
		get_pb_steps(st);
		find_min_pb(st);
		ft_pb(st);
	}
	ft_sort3(st);
	while (st->b)
	{
		get_pa_steps(st);
		find_min_pa(st);
		ft_pa(st);
	}
	ft_rotate(st);
}
