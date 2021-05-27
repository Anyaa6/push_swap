/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_checker_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:12:35 by abonnel           #+#    #+#             */
/*   Updated: 2021/05/26 15:29:01 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_data *d)
{
	t_stack		*a;
	int			nb;

	if (d->b)
		return (0);
	a = d->a;
	while (a->next)
	{
		nb = a->nb;
		if (nb < a->next->nb)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

void	display_ranks(t_data *d, t_stack *a, t_stack *b, int i)
{
	if (d->nb_in_a >= d->nb_in_b)
		i = d->nb_in_a;
	else
		i = d->nb_in_b;
	while (i > 0)
	{
		if (i <= d->nb_in_a)
		{
			dprintf(1, "%14d", a->rank);
			a = a->next;
		}
		else
		{
			dprintf(1, "%14s", "");
		}
		if (i <= d->nb_in_b)
		{
			dprintf(1, "	%-14d", b->rank);
			b = b->next;
		}
		dprintf(1, "\n");
		i--;
	}
	dprintf(1, "%14s	%-14s\n", "STACK A", "STACK B");
}
