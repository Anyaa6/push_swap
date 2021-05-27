/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_short.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:40:46 by abonnel           #+#    #+#             */
/*   Updated: 2021/05/27 12:02:06 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *d, int min, int max)
{
	if (d->a && d->a->rank == d->a->next->rank - 1 \
	&& d->a->next->next->rank == d->a->rank + 2)
		return ;
	if (d->a && d->a->rank == min)
	{
		rra(d, 1);
		sa(d, 1);
	}
	else if (d->a && d->a->rank != min && d->a->rank != max)
	{
		if (d->a->next && d->a->next->rank == min)
			sa(d, 1);
		else
			rra(d, 1);
	}
	else
	{
		if (d->a->next && d->a->next->rank == min)
			ra(d, 1);
		else
		{
			sa(d, 1);
			rra(d, 1);
		}
	}
}

void	push_smallest(t_data *d)
{
	t_stack	*cpy;
	int		nb_steps;

	cpy = d->a;
	if (d->nb_arg == 5)
	{
		nb_steps = to_get_each_nb(d, d->a, 0, 2);
		push_chunk_to_b(d, nb_steps, 0, 2);
	}
	else if (d->nb_arg == 4)
	{
		nb_steps = steps_to_rank(d->a, d->nb_in_a, 0);
		push_rank_to_b(d, nb_steps, 0);
	}
}

void	sort_short_stacks(t_data *d)
{
	if (d->nb_arg == 2)
		sa(d, 1);
	else if (d->nb_arg == 3)
		sort_three(d, d->nb_arg - 3, d->nb_arg - 1);
	else
	{
		push_smallest(d);
		sort_three(d, d->nb_arg - 3, d->nb_arg - 1);
		if (d->b && d->b->next && d->b->rank < d->b->next->rank)
			sb(d, 1);
		while (d->b && d->a && d->b->rank == d->a->rank - 1)
			pa(d, &d->a, &d->b, 1);
	}
}
