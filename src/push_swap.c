/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:55:50 by flauer            #+#    #+#             */
/*   Updated: 2023/05/01 13:24:25 by flauer           ###   ########.fr       */
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

int	ft_cont(t_list *elm)
{
	return (*(int *)elm->content);
}

int	ft_max(t_list *lst)
{
	int	max;

	max = ft_cont(lst);
	while (lst)
	{
		if (ft_cont(lst) > max)
			max = ft_cont(lst);
		lst = lst->next;
	}
	return (max);
}

int	ft_min(t_list *lst)
{
	int	min;

	min = ft_cont(lst);
	while (lst)
	{
		if (ft_cont(lst) < min)
			min = ft_cont(lst);
		lst = lst->next;
	}
	return (min);
}

bool	ft_sorted(t_state *st)
{
	t_list *tmp;

	if (ft_lstsize(st->b) > 0)
		return (false);
	tmp = st->a;
	while (tmp->next)
	{
		if (ft_cont(tmp) > ft_cont(tmp->next))
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

int ft_sorted_but_rotated(t_state *st)
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
		if (ft_cont(lst) > ft_cont(next))
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
	while (!ft_sorted(st))
		ft_rra(st);
}

void	ft_rotus(t_state *st)
{
	while (!ft_sorted(st))
		ft_ra(st);
}

void	ft_rotate(t_state *st, int pos)
{
	int		len;
	t_list *lst;

	lst = st->a;
	len = ft_lstsize(lst);
	if (pos > len / 2)
		ft_rrotus(st);
	else
		ft_rotus(st);
}

void	ft_sort3(t_state *st)
{
	int	sp;

	while (!ft_sorted(st))
	{
		sp = ft_sorted_but_rotated(st);
		if (sp)
			return (ft_rotate(st, sp));
		else
			ft_sa(st);
	}
}

int	ft_ins(t_state *st)
{
	int		val;
	t_list *tmp;

	val = ft_cont(st->b);
	tmp = st->a;
	while (tmp)
	{

	}
}

void	ft_sort5(t_state *st)
{
	int	sp;

	while (ft_lstsize(st->a) > 3)
		ft_pb(st);
	if (!(sp = ft_sorted_but_rotated(st)))
		ft_sa(st);
	while (st->b)
	{
		sp = ft_ins(st);
	}
}

int	main(int argc, char *argv[])
{
	t_state	st;

	if (argc < 2)
		return (0);
	if (!init(argc, argv, &st))
		return (write(1, "Error\n", 6));
	
	if (ft_lstsize(st.a) == 3)
		ft_sort3(&st);
	return (0);
}
