/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:58:47 by flauer            #+#    #+#             */
/*   Updated: 2023/05/09 13:00:52 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	content(t_list *elm)
{
	return (((t_elm *)elm->content)->content);
}

int	get_id(t_list *elm)
{
	return (((t_elm *)elm->content)->id);
}

int	nsteps(t_list *elm)
{
	return (((t_elm *)elm->content)->nsteps);
}

t_elm	*new_elm(int content)
{
	t_elm	*ret;

	ret = malloc(sizeof(t_elm));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->id = 0;
	ret->nsteps = 0;
	return (ret);
}
