/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:29:51 by flauer            #+#    #+#             */
/*   Updated: 2023/05/09 12:42:04 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_rot_combined(t_state *st, int nra, int nrb)
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
