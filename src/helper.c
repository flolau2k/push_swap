/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:58:49 by flauer            #+#    #+#             */
/*   Updated: 2023/04/27 09:59:26 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_putelm(void	*content)
{

	printf("%d", *(int*)content);
}

void	ft_putlst(t_list *lst)
{
	ft_lstiter(lst, &ft_putelm);
}

int	ft_alen(const char **a)
{
	int	i;

	i = 0;
	while (a[i])
		++i;
	return (i);
}
