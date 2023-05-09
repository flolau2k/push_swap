/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:30:49 by flauer            #+#    #+#             */
/*   Updated: 2023/05/09 16:35:03 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
