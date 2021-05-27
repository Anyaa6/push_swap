/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:16:58 by abonnel           #+#    #+#             */
/*   Updated: 2021/05/26 15:27:25 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *d, int display)
{
	t_stack			*tmp;
	t_stack			**s;

	s = &d->a;
	if (!(*s) || !((*s)->next))
		return ;
	tmp = (*s)->next;
	(*s)->next = (*s)->next->next;
	tmp->next = *s;
	*s = tmp;
	d->ins_nb++;
	if (display == 1)
		dprintf(1, "sa\n");
}

void	sb(t_data *d, int display)
{
	t_stack			*tmp;
	t_stack			**s;

	s = &d->b;
	if (!(*s) || !((*s)->next))
		return ;
	tmp = (*s)->next;
	(*s)->next = (*s)->next->next;
	tmp->next = *s;
	*s = tmp;
	d->ins_nb++;
	if (display == 1)
		dprintf(1, "sb\n");
}

void	ss(t_data *d, int display)
{
	sa(d, 0);
	sb(d, 0);
	d->ins_nb--;
	if (display == 1)
		dprintf(1, "ss\n");
}

void	pa(t_data *d, t_stack **a, t_stack **b, int display)
{
	t_stack			*tmp;

	if (!(*b))
		return ;
	d->nb_in_a++;
	d->nb_in_b--;
	if (!(*a))
	{
		*a = *b;
		*b = (*b)->next;
		(*a)->next = NULL;
	}
	else
	{
		tmp = *a;
		*a = *b;
		*b = (*b)->next;
		(*a)->next = tmp;
	}
	d->ins_nb++;
	if (display == 1)
		dprintf(1, "pa\n");
}

void	pb(t_data *d, t_stack **a, t_stack **b, int display)
{
	t_stack			*tmp;

	if (!(*a))
		return ;
	d->nb_in_a--;
	d->nb_in_b++;
	if (!(*b))
	{
		*b = *a;
		*a = (*a)->next;
		(*b)->next = NULL;
	}
	else
	{
		tmp = *b;
		*b = *a;
		*a = (*a)->next;
		(*b)->next = tmp;
	}
	d->ins_nb++;
	if (display == 1)
		dprintf(1, "pb\n");
}
