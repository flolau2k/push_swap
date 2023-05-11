/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:35:04 by flauer            #+#    #+#             */
/*   Updated: 2023/05/11 09:36:09 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putelm(void	*content)
{
	t_elm	*elm;

	elm = content;
	
	ft_printf("%d	", elm->content);
	ft_printf("%d	", elm->id);
	ft_printf("%d	", elm->nsteps);
	ft_printf("\n");
}

void	ft_putlst(t_list *lst)
{
	ft_lstiter(lst, &ft_putelm);
	ft_printf("\n");
}

void	ft_putstate(t_state *st)
{
	ft_printf("stack a: \n");
	ft_putlst(st->a);
	ft_printf("\n");
	ft_printf("stack b: \n");
	ft_putlst(st->b);
	ft_printf("\n --------- \n");
}
