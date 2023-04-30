/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:55:50 by flauer            #+#    #+#             */
/*   Updated: 2023/05/01 00:07:50 by flauer           ###   ########.fr       */
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
#include <stdio.h>
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
			if (!((ft_cont(st->a) / sort.factor) % 2))
			{
				ft_pb(st);
				// ft_rb(st);
			}
			else
				ft_ra(st);
			++sort.i;
			// ft_putstate(st);
			// getchar();
		}
		while(st->b)
		{
			ft_pa(st);
			//ft_ra(st);
		}
		// ft_putstate(st);
		// getchar();
		sort.factor *= 2;
	}
}

void	ft_sort3(t_state *st)
{
	while (!ft_sorted(st))
	{
		// ft_putstate(st);
		// getchar();
		if (ft_cont(st->a) > ft_cont(st->a->next) && ft_cont(st->a->next) > \
			ft_cont(st->a->next->next))
		{
			ft_sa(st);
			ft_rra(st);
		}
		else if (ft_cont(st->a) > ft_cont(st->a->next) && ft_cont(st->a) < \
				ft_cont(st->a->next->next))
				ft_sa(st);
		else
			ft_ra(st);
		// ft_putstate(st);
		// getchar();
	}
}

void	ft_sort5(t_state *st)
{
	t_sort	sort;

	sort.len = ft_lstsize(st->a);
	sort.i = sort.len;
	while (sort.i > 3)
	{
		ft_pb(st);
		++sort.i;
	}
	if (ft_cont(st->a) > ft_cont(st->a->next))
		ft_sa(st);
	
}

int	main(int argc, char *argv[])
{
	t_state	st;

	if (!init(argc, argv, &st))
		return (write(1, "Error\n", 6));
	// ft_putstate(&st);
	if (ft_lstsize(st.a) == 3)
		ft_sort3(&st);
	ft_sort(&st);
	// ft_putstate(&st);
	return (0);
}
