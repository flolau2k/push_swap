/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:58:49 by flauer            #+#    #+#             */
/*   Updated: 2023/05/04 13:55:19 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putelm(void	*content)
{
	ft_printf("%d ", *(int *)((t_elm *)content)->content);
}

void	ft_putid(void *content)
{
	t_elm	*elm;

	elm = content;
	ft_printf("%d ", elm->id);
}

void	ft_putlst(t_list *lst)
{
	ft_lstiter(lst, &ft_putelm);
	ft_printf("\n");
	ft_lstiter(lst, &ft_putid);
}

void	ft_putstate(t_state *st)
{
	ft_printf("stack a: \n");
	ft_putlst(st->a);
	ft_printf("\n");
	// ft_printf("stack b: ");
	// ft_putlst(st->b);
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

int	content(t_list *elm)
{
	return (*((t_elm *)elm->content)->content);
}

int	id(t_list *elm)
{
	return (((t_elm *)elm->content)->id);
}

int	ft_max(t_list *lst)
{
	int	max;

	max = content(lst);
	while (lst)
	{
		if (content(lst) > max)
			max = content(lst);
		lst = lst->next;
	}
	return (max);
}

int	ft_min(t_list *lst)
{
	int	min;

	min = content(lst);
	while (lst)
	{
		if (content(lst) < min)
			min = content(lst);
		lst = lst->next;
	}
	return (min);
}
