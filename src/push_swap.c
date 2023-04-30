/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:55:50 by flauer            #+#    #+#             */
/*   Updated: 2023/04/30 19:02:50 by flauer           ###   ########.fr       */
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
		if (ft_cont(lst) > min)
			min = ft_cont(lst);
		lst = lst->next;
	}
	return (min);
}

typedef struct s_sort
{
	int	max;
	int	factor;
	int	len;
	int	i;
}	t_sort;

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

// TODO negative numbers!
// Optimize ... 
void	ft_sort(t_state *st)
{
	t_sort	sort;

	sort.factor = 1;
	sort.len = ft_lstsize(st->a);
	sort.max = ft_max(st->a);
	while (!ft_sorted(st) && sort.factor <= sort.max)
	{
		sort.i = 0;
		while(sort.i < sort.len)
		{
			if ((ft_cont(st->a) / sort.factor) % 2)
			{
				ft_pb(st);
				ft_rb(st);
			}
			else
				ft_ra(st);
			++sort.i;
		}
		while(st->b)
		{
			ft_pa(st);
			ft_ra(st);
		}
		sort.factor *= 2;
	}
}

int	main(int argc, char *argv[])
{
	t_state	st;

	if (!init(argc, argv, &st))
		return (write(1, "Error\n", 6));
	//ft_putstate(&st);
	ft_sort(&st);
	//ft_putstate(&st);
	return (0);
}
