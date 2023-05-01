// #include <stdio.h>
// void	ft_sort5(t_state *st)
// {
// 	int	i;

// 	i = ft_lstsize(st->a);
// 	while (i > 2)
// 	{
// 		ft_pb(st);
// 		++i;
// 	}
// 	if (ft_cont(st->a) > ft_cont(st->a->next))
// 		ft_sa(st);
// 	while (st->b)
// 	{
// 		if (ft_cont(st->b) < ft_cont(st->a))
// 			ft_pa(st);
// 		else if (ft_cont(st->b) > ft_cont(st->a) && ft_cont(ft_lstlast(st->a)) < ft_cont(st->b))
// 		{
// 			ft_pa(st);
// 			ft_ra(st);
// 		}
// 		else
// 		{
// 			ft_ra(st);
// 		}
// 		ft_putstate(st);
// 		getchar();
// 	}
// }


	// while (!ft_sorted(st))
	// {
	// 	if (ft_cont(st->a) > ft_cont(st->a->next) && ft_cont(st->a->next) > \
	// 		ft_cont(st->a->next->next))
	// 	{
	// 		ft_sa(st);
	// 		ft_rra(st);
	// 	}
	// 	else if (ft_cont(st->a) > ft_cont(st->a->next) && ft_cont(st->a) < \
	// 			ft_cont(st->a->next->next))
	// 			ft_sa(st);
	// 	else
	// 		ft_ra(st);
	// }


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
	

int ft_sorted_but_rotated(t_state *st)
{
	int		c;
	t_list	*lst;
	int		i;
	int		ret;
	int		max;
	int		min;

	c = 0;
	i = 0;
	lst = st->a;
	max = ft_max(lst);
	min = ft_min(lst);
	while (++i && lst->next)
	{
		if (ft_cont(lst) > ft_cont(lst->next) && \
			ft_cont(lst) == max && ft_cont(lst->next) == min)
		{
			++c;
			ret = i;
		}
		else
		lst = lst->next;
	}
	if (c == 1)
		return (ret);
	return (0);
}