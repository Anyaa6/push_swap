/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:45:25 by abonnel           #+#    #+#             */
/*   Updated: 2021/05/26 15:30:40 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libgnl_normv3/libft.h"

typedef struct s_stack
{
	int				nb;
	int				rank;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	int				nb_arg;
	t_stack			*a;
	t_stack			*b;
	int				nb_in_a;
	int				nb_in_b;
	int				ins_nb;
}	t_data;

/*
** check_arguments.c
*/

void	check_arg(t_data *d, char **argv, int argc);

/*
** push_checker_list_functions.c
*/

t_stack	*newnode(int content);
t_stack	*before_last(t_stack *s);
t_stack	*go_lstend(t_stack *lst);
void	lstadd(t_stack **a, t_stack *new);
void	del_list(t_stack **node, t_data *d);

/*
** push_checker_utils.c
*/

int		is_sorted(t_data *d);
void	display_ranks(t_data *d, t_stack *a, t_stack *b, int i);

/*
** push_checker_error.c
*/

void	error(t_data *d, int err);
void	free_memory(t_data *d);

/*
** push_checker_instructions.c
*/

void	take_ins_and_execute(t_data *d);
void	exec_ins(t_data *d, char *ins);

/*
** push_swap_ranking.c
*/

void	nb_to_rank_set_pivot(t_data *d);

/*
** push_swap_sort.c
*/

void	sort_short_stacks(t_data *d);
void	sort_three(t_data *d, int min, int max);

/*
** push_swap_sort_iterations.c
*/

void	sort_stack_iterations(t_data *d);

/*
** push_swap_sort_utils.c
*/

int		steps_to_rank(t_stack *s, int nb_in_s, int rank);
void	push_rank_to_b(t_data *d, int nb_steps, int rank);
int		to_get_each_nb(t_data *d, t_stack *a, int i, int wid);
void	push_chunk_to_b(t_data *d, int nb_steps, int i, int wid);

/*
** operations_swap_push.c
*/

void	sa(t_data *d, int display);
void	sb(t_data *d, int display);
void	ss(t_data *d, int display);
void	pa(t_data *d, t_stack **a, t_stack **b, int display);
void	pb(t_data *d, t_stack **a, t_stack **b, int display);

/*
** operations_rotate.c
*/

void	ra(t_data *d, int display);
void	rb(t_data *d, int display);
void	rr(t_data *d, int display);

/*
** operation_rev_rotate.c
*/

void	rra(t_data *d, int display);
void	rrb(t_data *d, int display);
void	rrr(t_data *d, int display);

#endif