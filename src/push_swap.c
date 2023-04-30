/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:55:50 by flauer            #+#    #+#             */
/*   Updated: 2023/04/30 15:40:45 by flauer           ###   ########.fr       */
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

// typedef struct s_sort
// {
// 	int		max;
// 	int		min;
// 	int		mid;
// 	t_list	*elma;
// 	t_list	*elmb;
// }	t_sort;

// TODO negative numbers!
// Optimize ... 
void	ft_sort(t_state *st)
{
	int	max;
	int	factor;
	int	len;
	int	i = 0;

	factor = 1;
	len = ft_lstsize(st->a);
	max = ft_max(st->a);
	while (factor <= max)
	{
		i = 0;
		while(i < len)
		{
			if ((ft_cont(st->a) / factor) % 2)
			{
				ft_pb(st);
				ft_rb(st);
			}
			else
				ft_ra(st);
			++i;
		}
		while(st->b)
		{
			ft_pa(st);
			ft_ra(st);
		}
		factor *= 2;
	}
}

int	main(int argc, char *argv[])
{
	t_state	st;

	if (!init(argc, argv, &st))
		return (write(1, "Error\n", 6));
	ft_putstate(&st);
	ft_sort(&st);
	ft_putstate(&st);
	return (0);
}
