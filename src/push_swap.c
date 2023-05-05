/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:55:50 by flauer            #+#    #+#             */
/*   Updated: 2023/05/05 14:56:23 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_rrotn(t_state *st, int n, char lst)
{
	if (lst == 'a')
	{
		while (n-- > 0)
			ft_rra(st);
	}
	else
	{
		while (n-- > 0)
			ft_rrb(st);
	}
}

void	ft_rotn(t_state *st, int n, char lst)
{
	if (lst == 'a')
	{
		while (n-- > 0)
			ft_ra(st);
	}
	else
	{
		while (n-- > 0)
			ft_rb(st);
	}
}

void	ft_rotate(t_state *st)
{
	int		len;
	t_list	*lst;
	int 	pos;

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

/// @brief find the insert position for the element src into list dst at the 
/// correct location. expect dst to be sorted already, but may be rotated.
/// @param dst destination list
/// @param src source element
/// @return position to insert; number of rotate operations respectively. 
/// if return is < 0, reverse rotation is needed, else normal rotation.
int	_ft_ins(t_list *dst, t_list *src)
{
	t_ins	ins;

	ins.len = ft_lstsize(dst);
	ins.tmp = dst;
	ins.i = 0;
	ins.ret = 0;
	ins.thres = content(src);
	if (content(dst) > content(src) && content(ft_lstlast(dst)) < content(src))
		return (ins.i);
	while (ins.tmp->next)
	{
		++ins.i;
		if (content(ins.tmp) < ins.thres && content(ins.tmp->next) > ins.thres)
			break ;
		ins.tmp = ins.tmp->next;
	}
	if (ins.i <= ins.len / 2)
		return (ins.i);
	else
		return (ins.i - ins.len);
}

/// @brief find the correct location for the top of b to insert in a.
/// expect a to be sorted already, but may be rotated. Also expect the
/// Stack a to contain the largest and smallest value already.
/// @param st state
int	ft_ins(t_state *st)
{
	return (_ft_ins(st->a, st->b));
}

bool	same_chunk(t_state *st, int i, int j)
{
	int	chunk;
	int	chunk_size;

	chunk = 1;
	chunk_size = st->len / st->num_chunks;
	while (chunk <= st->num_chunks)
	{
		if (i >= chunk_size * (chunk - 1) && i < chunk_size * chunk)
			break ;
		if (chunk == st->num_chunks && i >= chunk_size * (chunk - 1) && i < st->len)
			break ;
		++chunk;
	}
	if (j >= chunk_size * (chunk - 1) && j < chunk_size * chunk)
		return (true);
	if (chunk == st->num_chunks && j >= chunk_size * (chunk - 1) && j < st->len)
		return (true);
	return (false);
}

/// @brief work with IDs!
/// @param st 
int	sort_in_chunks(t_state *st)
{
	int		i;
	int		len;
	t_list	*tmp;
	int		src_id;

	tmp = st->b;
	i = 0;
	src_id = id(st->a);
	len = ft_lstsize(tmp);
	while (tmp)
	{
		if (same_chunk(st, id(tmp), src_id))
			break ;
		tmp = tmp->next;
		++i;
	}
	if (i < len / 2)
		return (i);
	else
	{
		while (tmp && same_chunk(st, id(tmp), src_id))
		{
			++i;
			tmp = tmp->next;
		}
		return (i - len);
	}
}

void	best_rot(t_state *st, char lst_id, int c)
{
	int	len;
	t_list *lst;

	lst = st->a;
	if (lst_id == 'b' || lst_id == 'B')
		lst = st->b;
	len = ft_lstsize(lst);
	if (c < len / 2)
		ft_rotn(st, c, lst_id);
	else
		ft_rrotn(st, len - c, lst_id);
}

void	ft_presort(t_state *st)
{
	int	pos;

	if (ft_lstsize(st->b) == 0)
		return (ft_pb(st));
	pos = sort_in_chunks(st);
	if (pos == 0)
		return (ft_pb(st));
	else if (pos > 0)
		return (ft_rotn(st, pos, 'b'), ft_pb(st));
	else
		return (ft_rrotn(st, -pos, 'b'), ft_pb(st));
}

void	ft_sortn(t_state *st)
{
	int	idx;

	while (ft_lstsize(st->a) > 3)
	{
		if (!(content(st->a) == st->min) && !(content(st->a) == st->max))
			ft_presort(st);
		else
			do_op(st, RA);
	}
	ft_sort3(st);
	while (st->b)
	{
		idx = ft_ins(st);
		if (idx > 0)
			ft_rotn(st, idx, 'a');
		else if (idx < 0)
			ft_rrotn(st, -idx, 'a');
		ft_pa(st);
	}
	ft_rotate(st);
}

int	main(int argc, char *argv[])
{
	t_state	st;

	if (argc < 2)
		return (0);
	if (!init(argc, argv, &st))
		return (write(1, "Error\n", 6));
	//ft_radix(&st);
	// if (ft_lstsize(st.a) <= 50)
	ft_sortn(&st);
	// else
	// 	ft_radix(&st);
	// do_op(&st, FLUSH);
	return (0);
}
