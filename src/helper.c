/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:58:49 by flauer            #+#    #+#             */
/*   Updated: 2023/05/08 10:29:46 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putelm(void	*content)
{
	t_elm	*elm;

	elm = content;
	
	ft_printf("%d	", *elm->content);
	ft_printf("%d	", elm->id);
	ft_printf("%d	", elm->nsteps);
	ft_printf("\n");
}

int	get_pos(t_list *lst, t_list *elm)
{
	int	ret;
	t_list *curr_elm;

	ret = 0;
	curr_elm = lst;
	while (curr_elm && get_id(curr_elm) != get_id(elm))
	{
		curr_elm = curr_elm->next;
		++ret;
	}
	return (opt_rot(lst, ret));
}

int	get_pos_id(t_list *lst, int id)
{
	int	ret;
	t_list *curr_elm;

	ret = 0;
	curr_elm = lst;
	while (curr_elm && get_id(curr_elm) != id)
	{
		curr_elm = curr_elm->next;
		++ret;
	}
	return (opt_rot(lst, ret));
}

int	opt_rot(t_list *lst, int i)
{
	int	ret;
	int	len;
	
	len = ft_lstsize(lst);
	if (i <= len / 2)
		return (i);
	else
		return (i - len);
}

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
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

int	get_id(t_list *elm)
{
	return (((t_elm *)elm->content)->id);
}

int	nsteps(t_list *elm)
{
	return (((t_elm *)elm->content)->nsteps);
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
