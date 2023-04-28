/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:58:49 by flauer            #+#    #+#             */
/*   Updated: 2023/04/28 12:52:33 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putelm(void	*content)
{
	ft_printf("element: %d\n", *(int *)content);
}

void	ft_putlst(t_list *lst)
{
	ft_lstiter(lst, &ft_putelm);
}

void	clear_elm(void *content)
{
	*(int *) content = 0;
	free(content);
}

int	ft_alen(const char **a)
{
	int	i;

	i = 0;
	while (a[i])
		++i;
	return (i);
}
