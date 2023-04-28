/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:58:49 by flauer            #+#    #+#             */
/*   Updated: 2023/04/28 13:53:50 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putelm(void	*content)
{
	ft_printf("%d ", *(int *)content);
}

void	ft_putlst(t_list *lst)
{
	ft_lstiter(lst, &ft_putelm);
}

void	ft_putstate(t_state *st)
{
	ft_printf("stack a: ");
	ft_putlst(st->a);
	ft_printf("\n");
	ft_printf("stack b: ");
	ft_putlst(st->b);
	ft_printf("\n --------- \n");
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
