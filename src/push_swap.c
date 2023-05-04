/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:55:50 by flauer            #+#    #+#             */
/*   Updated: 2023/05/04 12:04:13 by flauer           ###   ########.fr       */
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

int	rotated(t_state *st)
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
		if (content(lst) > content(next))
		{
			++c;
			ret = i;
		}
		lst = lst->next;
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
		do_op(st, RRA);
}

void	ft_rotus(t_state *st)
{
	while (!sorted(st))
		do_op(st, RA);
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
	pos = rotated(st);
	if (pos == -1)
		ft_printf("rot error\n");
	if (pos > len / 2)
		ft_rrotus(st);
	else
		ft_rotus(st);
}

void	ft_rrotn(t_state *st, int n)
{
	while (n-- > 0)
		do_op(st, RRA);
}

void	ft_rotn(t_state *st, int n)
{
	while (n-- > 0)
		do_op(st, RA);
}

void	ft_sort3(t_state *st)
{
	if (rotated(st) >= 0)
		return ;
	else
		do_op(st, SA);
}

/// @brief find the number of operations needed for the first element of src
/// to be inserted into dst at the correct location.
/// @param dst destination list
/// @param src source element
/// @return position to insert; number of rotate operations respectively. 
/// if return is < 0, reverse rotation is needed, else normal rotation.
int	_ft_ins(t_list *dst, t_list *src)
{
	t_list	*tmp;
	int		len;
	int		i;

	len = ft_lstsize(dst);
	tmp = dst;
	i = 0;
	if (content(dst) > content(src) && content(ft_lstlast(dst)) < content(src))
		return (i);
	while (tmp->next)
	{
		++i;
		if (content(tmp) < content(src) && content(tmp->next) > content(src))
			break ;
		tmp = tmp->next;
	}
	if (i <= len / 2)
		return (i);
	else
		return (i - len);
}

/// @brief find the correct location for the top of b to insert in a.
/// expect a to be sorted already, but may be rotated. Also expect the
/// Stack a to contain the largest and smallest value already.
/// @param st state
int	ft_ins(t_state *st)
{
	return (_ft_ins(st->a, st->b));
}

/// @brief pushes from a to b in a way that the stack b will be presorted into
/// chunks.
/// @param st state
void	ft_presort(t_state *st)
{
	if (ft_lstsize(st->b) == 0)
		return (do_op(st, PB));
	
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
	if (rotated(st) == -1)
	{
		ft_printf("assert false: sort3 rotated.");
		return ;
	}
	while (st->b)
	{
		idx = ft_ins(st);
		if (idx > 0)
			ft_rotn(st, idx);
		else if (idx < 0)
			ft_rrotn(st, -idx);
		do_op(st, PA);
	}
}

void	get_num_ops_pb(t_state *st)
{
	t_list	*elm;

	elm = st->a;
	while (elm)
	{
		
	}
}

int	main(int argc, char *argv[])
{
	t_state	st;

	if (argc < 2)
		return (0);
	if (!init(argc, argv, &st))
		return (write(1, "Error\n", 6));
	//ft_printf("low, high = %d, %d\n", st.low, st.high);
	ft_radix(&st);
	do_op(&st, FLSH);
	return (0);
}
