/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:55:50 by flauer            #+#    #+#             */
/*   Updated: 2023/04/25 11:40:03 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_dup(t_list **a, int *num)
{
	t_list	*item;
	
	item = *a;
	while (item)
	{
		if (*(int*)item->content == *num)
			return (true);
		item = item -> next;
	}
	return (false);
}

bool	init_stack(t_list **a, char **arg)
{
	int		*num;
	t_list	*new;

	num = malloc(sizeof(*num));
	*num = ft_atoi(*arg); // todo check for > INT_MAX or < INT_MIN
	if (!check_dup(a, num))
	{
		new = ft_lstnew(num);
		ft_lstadd_back(a, new);
	}
	else
		return (false);
	return (true);
}

bool	proc_input(int argc, char *argv[], t_list **a)
{
	int		i;
	char	**args[argc];

	i = 0;
	while (++i < argc)
		args[i - 1] = ft_split(argv[i], ' ');
	args[i - 1] = NULL;
	i = 0;
	while (++i < argc)
	{
		if (!init_stack(a, args[i - 1]))
			return (false);
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	b = ft_lstnew(NULL);
	a = NULL;
	proc_input(argc, argv, &a);
	
	return (0);
}
