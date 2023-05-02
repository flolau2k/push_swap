/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:56:01 by flauer            #+#    #+#             */
/*   Updated: 2023/05/02 17:27:37 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include "../libft/include/libft.h"
# ifdef __linux
#  include <stdint.h>
# endif

typedef struct s_state
{
	t_list	*a;
	t_list	*b;
	int		max;
	int		min;
	int		low;
	int		mid;
	int		high;
}	t_state;

typedef struct s_sort
{
	int	max;
	int	factor;
	int	len;
	int	i;
}	t_sort;

int		main(int argc, char *argv[]);
bool	init(int argc, char *argv[], t_state *st);
bool	init_stack(int argc, char *args[], t_state *st);
void	free_stacks(t_state *st);
int		content(t_list *elm);

// swap.c
void	ft_sa(t_state *st);
void	ft_sb(t_state *st);
void	ft_ss(t_state *st);

// push.c
void	ft_pa(t_state *st);
void	ft_pb(t_state *st);

// rot.c
void	ft_ra(t_state *st);
void	ft_rb(t_state *st);
void	ft_rr(t_state *st);

// rev_rot.c
t_list	*ft_seclast(t_list *lst);
void	ft_rra(t_state *st);
void	ft_rrb(t_state *st);
void	ft_rrr(t_state *st);

// helper.c
void	ft_putelm(void	*content);
void	ft_putlst(t_list *lst);
int		ft_alen(const char **a);
void	clear_elm(void *content);
void	ft_putstate(t_state *st);

// init.c
bool	init_stack(int argc, char *args[], t_state *st);
void	free_stacks(t_state *st);
bool	init(int argc, char *argv[], t_state *st);

#endif // PUSH_SWAP_H