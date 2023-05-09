/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flauer <flauer@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:56:01 by flauer            #+#    #+#             */
/*   Updated: 2023/05/09 12:41:10 by flauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include "../libft/include/libft.h"
# ifdef __linux
#  include <stdint.h>
# endif

# define SA		1
# define SB		2
# define SS		3
# define PA		4
# define PB		5
# define RA		6
# define RB		7
# define RR		8
# define RRA	9
# define RRB	10
# define RRR	11
# define FLUSH	12

typedef struct s_state
{
	t_list	*a;
	t_list	*b;
	int		len;
	int		num_chunks;
}	t_state;

typedef struct s_elm
{
	int	content;
	int	id;
	int	nsteps;
}	t_elm;


int		main(int argc, char *argv[]);
bool	init(int argc, char *argv[], t_state *st);
int		content(t_list *elm);
int		get_id(t_list *elm);
bool	sorted(t_state *st);

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
int		opt_rot(t_list *lst, int i);
int		get_pos(t_list *lst, t_list *elm);
int		get_pos_id(t_list *lst, int i);
size_t	ft_abs(int i);
int		ft_alen(const char **a);

// init.c
bool	init(int argc, char *argv[], t_state *st);

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
int		_ft_ins(t_list *dst, t_list *src);
void	ft_rotn(t_state *st, int n, char lst);
void	ft_rrotn(t_state *st, int n, char lst);

// sort.c
void	ft_sortn(t_state *st);
void	ft_sort3(t_state *st);
void	ft_rotate(t_state *st);
int		rotated(t_list	*lst);
bool	sorted(t_state *st);

#endif // PUSH_SWAP_H