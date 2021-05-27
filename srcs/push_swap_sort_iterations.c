/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_iterations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:40:19 by abonnel           #+#    #+#             */
/*   Updated: 2021/05/27 12:06:56 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_next(t_data *d, int to_next, int nrank, void (*rot)(t_data *, int))
{
	int			rrb;

	rrb = 0;
	if (to_next < 0)
		rrb = 1;
	to_next = abs(to_next);
	while (to_next > 0)
	{
		if (d->b && d->b->rank == nrank - 1)
		{
			pa(d, &d->a, &d->b, 1);
			if (rrb == 1)
				continue ;
		}
		else if (d->b && d->b->rank == nrank - 2)
		{
			pa(d, &d->a, &d->b, 1);
			ra(d, 1);
			if (rrb == 1)
				continue ;
		}
		else
			(*rot)(d, 1);
		to_next--;
	}
}

void	get_next(t_data *d, int to_next, int nrank, void (*rot)(t_data *, int))
{
	go_next(d, to_next, nrank, rot);
	if (d->b && d->b->rank == nrank)
		pa(d, &d->a, &d->b, 1);
	if (d->a && d->a->next && d->a->rank > d->a->next->rank)
		sa(d, 1);
	if (d->a && go_lstend(d->a)->rank == d->a->rank - 1)
		rra(d, 1);
	else if (d->a && go_lstend(d->a)->rank == d->a->rank - 2 \
	&& before_last(d->a)->rank == d->a->rank - 1)
	{
		rra(d, 1);
		rra(d, 1);
		sa(d, 1);
	}
}

void	sort_rest(t_data *d)
{
	int		to_next;
	int		nrank;
	int		i;

	i = 0;
	nrank = d->nb_arg - d->nb_in_a - 1;
	while (d->nb_in_b > 2)
	{
		nrank = d->a->rank - 1;
		to_next = steps_to_rank(d->b, d->nb_in_b, nrank);
		if (to_next >= 0)
			get_next(d, to_next, nrank, &rb);
		else
			get_next(d, to_next, nrank, &rrb);
		i++;
	}
	if (d->b && d->b->next && d->b->rank < d->b->next->rank)
		sb(d, 1);
	pa(d, &d->a, &d->b, 1);
	if (d->a && go_lstend(d->a)->rank == d->a->rank - 1)
		rra(d, 1);
	pa(d, &d->a, &d->b, 1);
}

void	sort_stack_iterations(t_data *d)
{
	int		wid;
	int		i;
	int		nb_steps;

	i = 0;
	wid = 3;
	if (d->nb_arg > 20 && d->nb_arg < 300)
		wid = d->nb_arg / 4.5;
	else if (d->nb_arg >= 300)
		wid = d->nb_arg / 11;
	while (d->nb_in_a > 3 + wid)
	{
		nb_steps = to_get_each_nb(d, d->a, i, wid);
		push_chunk_to_b(d, nb_steps, i, wid);
		i += wid;
	}
	while (d->nb_in_a > 3)
	{
		if (d->a && d->a->rank >= d->nb_arg - 3 && d->a->rank <= d->nb_arg - 1)
			ra(d, 1);
		else
			pb(d, &d->a, &d->b, 1);
	}
	sort_three(d, d->nb_arg - 3, d->nb_arg - 1);
	sort_rest(d);
}
