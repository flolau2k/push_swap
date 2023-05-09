/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:55:50 by flauer            #+#    #+#             */
/*   Updated: 2023/05/08 14:07:39 by flauer           ###   ########.fr       */
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
/// also dst must already contain its smallest and largest element.
/// @param dst destination list
/// @param src source element
/// @return position to insert; number of rotate operations respectively. 
/// if return is < 0, reverse rotation is needed, else normal rotation.
int	_ft_ins(t_list *dst, t_list *src)
{
	t_list	*tmp;
	int		i;

	tmp = dst;
	i = 0;
	if (get_id(dst) > get_id(src) && get_id(ft_lstlast(dst)) < get_id(src))
		return (i);
	while (tmp->next)
	{
		++i;
		if (get_id(tmp) < get_id(src) && get_id(tmp->next) > get_id(src))
			break ;
		tmp = tmp->next;
	}
	return (opt_rot(dst, i));
}

/// @brief find the correct location for the top of b to insert in a.
/// expect a to be sorted already, but may be rotated. Also expect the
/// Stack a to contain the largest and smallest value already.
/// @param st state
int	ft_ins(t_state *st)
{
	return (_ft_ins(st->a, st->b));
}

int	get_chunk_id(t_state *st, int id)
{
	int	chunk;
	int	chunk_size;

	chunk = 1;
	chunk_size = st->len / st->num_chunks;
	while (chunk < st->num_chunks)
	{
		if (id >= chunk_size * (chunk - 1) && id < chunk_size * chunk)
			break ;
		++chunk;
	}
	return (chunk);
}

int	get_chunk(t_state *st, t_list *elm)
{
	return (get_chunk_id(st, get_id(elm)));
}

int	same_chunk_id(t_state *st, int i, int j)
{
	int	chi;
	int	chj;

	chi = get_chunk_id(st, i);
	chj = get_chunk_id(st, j);
	return (chi - chj);
}

int	same_chunk(t_state *st, t_list *i, t_list *j)
{
	int	chi;
	int	chj;

	chi = get_chunk(st, i);
	chj = get_chunk(st, j);
	return (chi - chj);
}

/// @brief work with IDs!
/// TODO: make sure, to insert a new chunk at the correct position!
/// @param st 
int	get_chunk_pos(t_state *st, t_list *elm)
{
	int		i;
	int		len;
	t_list	*tmp;

	tmp = st->b;
	i = 0;
	len = ft_lstsize(tmp);
	while (tmp && same_chunk(st, tmp, elm))
	{
		tmp = tmp->next;
		++i;
	}
	if (i <= len / 2)
		return (i);
	else
	{
		while (tmp && same_chunk(st, tmp, elm) == 0)
		{
			++i;
			tmp = tmp->next;
		}
		return (i - len);
	}
}

void	_rot_combined(t_state *st, int nra, int nrb)
{
	while (nra > 0 && nrb > 0)
	{
		ft_rr(st);
		--nra;
		--nrb;
	}
	if (nra > 0)
		ft_rotn(st, nra, 'a');
	if (nrb > 0)
		ft_rotn(st, nrb, 'b');
	while (nra < 0 && nrb < 0)
	{
		ft_rrr(st);
		++nra;
		++nrb;
	}
	if (nra < 0)
		ft_rrotn(st, -nra, 'a');
	if (nrb < 0)
		ft_rrotn(st, -nrb, 'b');
}

void	rot_for_pb(t_state *st, t_list *elm)
{
	int	nra;
	int	nrb;

	nra = get_pos(st->a, elm);
	nrb = get_chunk_pos(st, elm);
	_rot_combined(st, nra, nrb);
}

void	rot_for_pa(t_state *st, t_list *elm)
{
	int	nra;
	int	nrb;

	nrb = get_pos(st->b, elm);
	nra = _ft_ins(st->a, elm);
	_rot_combined(st, nra, nrb);
}


void	ft_presort(t_state *st)
{
	while (ft_lstsize(st->a) > 3)
	{
		get_pb_steps(st);
		find_min_pb(st);
		ft_pb(st);
	}
}

void	ft_sortn(t_state *st)
{
	int	idx;

	ft_presort(st);
	ft_sort3(st);
	while (st->b)
	{
		get_pa_steps(st);
		find_min_pa(st);
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
	ft_sortn(&st);
	return (0);
}
