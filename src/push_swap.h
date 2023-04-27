/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:56:01 by flauer            #+#    #+#             */
/*   Updated: 2023/04/27 10:00:19 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include "../libft/include/libft.h"

typedef struct s_state
{
	t_list *a;
	t_list *b;
}	t_state;

int		main(int argc, char **argv);
bool	init(int argc, char *argv[], t_state *st);
bool	init_stack(int argc, char *args[], t_state *st);

void	ft_sa(t_list **a);

// helper
void	ft_putelm(void	*content);
void	ft_putlst(t_list *lst);
int		ft_alen(const char **a);

#endif // PUSH_SWAP_H