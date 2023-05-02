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
// 	if (content(st->a) > content(st->a->next))
// 		ft_sa(st);
// 	while (st->b)
// 	{
// 		if (content(st->b) < content(st->a))
// 			ft_pa(st);
// 		else if (content(st->b) > content(st->a) && content(ft_lstlast(st->a)) < content(st->b))
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


	// while (!sorted(st))
	// {
	// 	if (content(st->a) > content(st->a->next) && content(st->a->next) > \
	// 		content(st->a->next->next))
	// 	{
	// 		ft_sa(st);
	// 		ft_rra(st);
	// 	}
	// 	else if (content(st->a) > content(st->a->next) && content(st->a) < \
	// 			content(st->a->next->next))
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
	if (content(st->a) > content(st->a->next))
		ft_sa(st);
	

int rotated(t_state *st)
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
		if (content(lst) > content(lst->next) && \
			content(lst) == max && content(lst->next) == min)
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