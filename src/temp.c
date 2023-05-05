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


// 	t_sort	sort;

// 	sort.len = ft_lstsize(st->a);
// 	sort.i = sort.len;
// 	while (sort.i > 3)
// 	{
// 		ft_pb(st);
// 		++sort.i;
// 	}
// 	if (content(st->a) > content(st->a->next))
// 		ft_sa(st);
	

// int rotated(t_state *st)
// {
// 	int		c;
// 	t_list	*lst;
// 	int		i;
// 	int		ret;
// 	int		max;
// 	int		min;

// 	c = 0;
// 	i = 0;
// 	lst = st->a;
// 	max = ft_max(lst);
// 	min = ft_min(lst);
// 	while (++i && lst->next)
// 	{
// 		if (content(lst) > content(lst->next) && \
// 			content(lst) == max && content(lst->next) == min)
// 		{
// 			++c;
// 			ret = i;
// 		}
// 		else
// 		lst = lst->next;
// 	}
// 	if (c == 1)
// 		return (ret);
// 	return (0);
// }


// void	ft_presort(t_state *st)
// {
// 	int	ops;
// 	int	curr_ops;
// 	t_list	*tmp;
// 	int		c;
// 	int		c_min;

// 	while (ft_lstsize(st->b) < 3)
// 		ft_pb(st);
// 	// if (!rotated(st->b))
// 	// 	ft_sb(st);
// 	while (ft_lstsize(st->a) > 3)
// 	{
// 		tmp = st->a;
// 		c = 0;
// 		c_min = 0;
// 		ops = sort_in_chunks(st, id(st->a));
// 		while (tmp)
// 		{
// 			if (!(content(tmp) == st->min) && !(content(tmp) == st->max))
// 			{
// 				curr_ops = sort_in_chunks(st, id(tmp));
// 				if (curr_ops + c < ops + c_min)
// 				{
// 					ops = curr_ops;
// 					c_min = c;
// 				}
// 			}
// 			++c;
// 			tmp = tmp->next;
// 		}
// 		best_rot(st, 'a', c_min);
// 		best_rot(st, 'b', ops);
// 		ft_pb(st);
// 	}
// }