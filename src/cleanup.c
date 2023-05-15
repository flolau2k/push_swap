/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:06:49 by flauer            #+#    #+#             */
/*   Updated: 2023/05/15 15:32:12 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	clear_lists(t_state *st)
{
	ft_lstclear(&st->a, &free);
	ft_lstclear(&st->b, &free);
}

void	free_splits(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
	splits = NULL;
}

void	cleanup_init(t_state *st, t_elm *elm)
{
	clear_lists(st);
	if (elm != NULL)
		free(elm);
}
