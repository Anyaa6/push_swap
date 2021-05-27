/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:35:10 by abonnel           #+#    #+#             */
/*   Updated: 2021/05/27 12:25:14 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	steps_to_rank(t_stack *s, int nb_in_s, int rank)
{
	int			r;
	int			rr;

	r = 0;
	while (s->next)
	{
		if (s->rank == rank)
		{
			break ;
		}
		s = s->next;
		r++;
	}
	rr = nb_in_s - r;
	if (r <= rr)
		return (r);
	else
		return (rr * -1);
}

void	push_rank_to_b(t_data *d, int nb_steps, int rank)
{
	if (nb_steps < 0)
	{
		nb_steps *= -1;
		while (nb_steps-- > 0)
			rra(d, 1);
		if (d->a && d->a->rank == rank)
			pb(d, &d->a, &d->b, 1);
	}
	else
	{
		while (nb_steps-- > 0)
			ra(d, 1);
		if (d->a && d->a->rank == rank)
			pb(d, &d->a, &d->b, 1);
	}
}

int	to_get_each_nb(t_data *d, t_stack *a, int i, int wid)
{
	int			r;
	int			rr;
	int			first;
	int			w_cp;

	r = 0;
	w_cp = wid;
	first = -1;
	while (a)
	{
		if (a->rank >= i && a->rank < i + wid)
		{
			if ((w_cp == wid && r != 0) || (first == -1 && w_cp == wid - 1))
				first = r;
			w_cp--;
			if (w_cp == 0)
				break ;
		}
		a = a->next;
		r++;
	}
	rr = d->nb_in_a - first;
	if (r <= rr)
		return (r);
	return (rr * -1);
}

void	push_chunk_to_b(t_data *d, int nb_steps, int i, int wid)
{
	int			pushes;

	pushes = 0;
	while (pushes < wid)
	{
		if (nb_steps < 0)
			rra(d, 1);
		else
			ra(d, 1);
		if (d->a && d->a->rank >= i && d->a->rank < i + wid)
		{
			pb(d, &d->a, &d->b, 1);
			pushes++;
		}
	}
}
