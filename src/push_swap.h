/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:56:01 by flauer            #+#    #+#             */
/*   Updated: 2023/05/17 09:24:32 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include "../libft/include/libft.h"
# ifndef NUM_CHUNKS
#  define NUM_CHUNKS 3
# endif

typedef struct s_state
{
	t_list	*a;
	t_list	*b;
	int		len;
}	t_state;

typedef struct s_elm
{
	int	content;
	int	id;
	int	nsteps;
}	t_elm;

int		main(int argc, char *argv[]);

// swap.c
void	_swap(t_list **lst);
void	ft_sa(t_state *st);
void	ft_sb(t_state *st);
void	ft_ss(t_state *st);

// push.c
void	_push(t_list **dst, t_list **src);
void	ft_pa(t_state *st);
void	ft_pb(t_state *st);

// rot.c
void	_rot(t_list **lst);
void	ft_ra(t_state *st);
void	ft_rb(t_state *st);
void	ft_rr(t_state *st);

// rev_rot.c
t_list	*ft_seclast(t_list *lst);
void	_rrot(t_list **lst);
void	ft_rra(t_state *st);
void	ft_rrb(t_state *st);
void	ft_rrr(t_state *st);

// helper.c
int		opt_rot(t_list *lst, int i);
int		get_pos(t_list *lst, t_list *elm);
int		get_pos_id(t_list *lst, int i);
size_t	ft_abs(int i);

// init.c
bool	init(int argc, char *argv[], t_state *st);
bool	init_stack(int argc, char *args[], t_state *st);
int		ft_alen(const char **a);

// presort.c
void	pre_quicksort(int **lst, int l, int r);
void	fill_ids(t_state *st, int **lst);

// element.c
int		content(t_list *elm);
int		get_id(t_list *elm);
int		nsteps(t_list *elm);
t_elm	*new_elm(int content);

// optimizers.c
void	get_pa_steps(t_state *st);
void	get_pb_steps(t_state *st);
size_t	get_steps_combined(int nra, int nrb);
void	find_min_pb(t_state *st);
void	find_min_pa(t_state *st);

// chunk_helper.c
int		get_chunk_id(t_state *st, int id);
int		get_chunk(t_state *st, t_list *elm);
int		same_chunk_id(t_state *st, int i, int j);
int		same_chunk(t_state *st, t_list *i, t_list *j);
int		get_chunk_pos(t_state *st, t_list *elm);

// rotation_helper.c
void	rot_for_pb(t_state *st, t_list *elm);
void	rot_for_pa(t_state *st, t_list *elm);
void	ft_rotn(t_state *st, int n, char lst);
void	ft_rrotn(t_state *st, int n, char lst);

// sort.c
void	ft_sortn(t_state *st);
void	ft_sort3(t_state *st);
void	ft_rotate(t_state *st);
int		rotated(t_list	*lst);

// insertion_helper.c
int		_ft_ins(t_list *dst, t_list *src);

// checks.c
bool	sorted(t_state *st);

// cleanup.c
void	clear_lists(t_state *st);
void	free_splits(char **splits);
void	cleanup_init(t_state *st, t_elm *elm);

// debug.c
void	ft_putelm(void	*content);
void	ft_putstate(t_state *st);
void	ft_putlst(t_list *lst);

#endif // PUSH_SWAP_H