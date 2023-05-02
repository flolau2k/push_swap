/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:55:50 by flauer            #+#    #+#             */
/*   Updated: 2023/05/02 11:16:57 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_ops(t_state *st)
{
	ft_printf("start: \n");
	ft_putstate(st);
	ft_pb(st);
	ft_putstate(st);
	ft_pa(st);
	ft_putstate(st);
	ft_ra(st);
	ft_putstate(st);
	ft_pb(st);
	ft_pb(st);
	ft_putstate(st);
	ft_rr(st);
	ft_putstate(st);
	ft_rrr(st);
	ft_putstate(st);
}

int	content(t_list *elm)
{
	return (*(int *)elm->content);
}

int	ft_max(t_list *lst)
{
	int	max;

	max = content(lst);
	while (lst)
	{
		if (content(lst) > max)
			max = content(lst);
		lst = lst->next;
	}
	return (max);
}

int	ft_min(t_list *lst)
{
	int	min;

	min = content(lst);
	while (lst)
	{
		if (content(lst) < min)
			min = content(lst);
		lst = lst->next;
	}
	return (min);
}

bool	sorted(t_state *st)
{
	t_list *tmp;

	if (ft_lstsize(st->b) > 0)
		return (false);
	tmp = st->a;
	while (tmp->next)
	{
		if (content(tmp) > content(tmp->next))
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

int rotated(t_state *st)
{
	int		c;
	t_list	*lst;
	t_list	*next;
	int		i;
	int		ret;

	c = 0;
	i = 0;
	lst = st->a;
	while (++i && lst)
	{
		if (!lst->next)
			next = st->a;
		else
			next = lst->next;
		if (content(lst) > content(next))
		{
			++c;
			ret = i;
		}
		lst = lst->next;
	}
	if (c == 1)
		return (ret);
	return (0);
}

/// @brief reverse rotate until sorted
/// @param st state
void	ft_rrotus(t_state *st)
{
	while (!sorted(st))
		ft_rra(st);
}

void	ft_rotus(t_state *st)
{
	while (!sorted(st))
		ft_ra(st);
}

void	ft_rotate(t_state *st)
{
	int		len;
	t_list *lst;
	int 	pos;

	if (sorted(st))
		return ;
	lst = st->a;
	len = ft_lstsize(lst);
	pos = rotated(st);
	if (pos > len / 2)
		ft_rrotus(st);
	else
		ft_rotus(st);
}

void	ft_rrotn(t_state *st, int n)
{
	while (n-- > 0)
		ft_rra(st);
}

void	ft_rotn(t_state *st, int n)
{
	while (n-- > 0)
		ft_ra(st);
}

void	ft_sort3(t_state *st)
{
	while (!sorted(st))
	{
		if (rotated(st))
			return ;
		else
			ft_sa(st);
	}
}

/// @brief find the correct location for the top of b to insert in a.
/// expect a to be sorted already, but may be rotated.
/// @param st state
int	ft_ins(t_state *st)
{
	t_list *tmp;
	int		len;
	int		i;

	len = ft_lstsize(st->a);
	tmp = st->a;
	i = 0;
	if (content(st->a) > content(st->b) && content(ft_lstlast(st->a)) < content(st->b))
		return (i);
	while (tmp->next)
	{
		++i;
		if (content(tmp) < content(st->b) && content(tmp->next) > content(st->b))
			break ;
		tmp = tmp->next;
	}
	if (i <= len / 2)
		return (i);
	else
		return (i - len);
}

void	ft_sortn(t_state *st)
{
	int	idx;

	while (ft_lstsize(st->a) > 3)
		ft_pb(st);
	if (!rotated(st))
		ft_sa(st);
	while (st->b)
	{
		idx = ft_ins(st);
		ft_printf("idx: %i\n", idx);
		ft_putstate(st);
		if (idx > 0)
			ft_rrotn(st, idx);
		else if (idx < 0)
			ft_rotn(st, -idx);
		ft_putstate(st);
		ft_pa(st);
	}
}

int	main(int argc, char *argv[])
{
	t_state	st;

	if (argc < 2)
		return (0);
	if (!init(argc, argv, &st))
		return (write(1, "Error\n", 6));
	ft_sortn(&st);
	ft_putstate(&st);
	//ft_rotate(&st);
	return (0);
}
