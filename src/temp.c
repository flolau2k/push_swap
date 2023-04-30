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