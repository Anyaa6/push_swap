/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rev_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:55:52 by abonnel           #+#    #+#             */
/*   Updated: 2021/05/26 15:18:52 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *d, int display)
{
	t_stack		**s;
	t_stack		*tmp;

	s = &d->a;
	if (!(*s) || !((*s)->next))
		return ;
	tmp = before_last(*s);
	go_lstend(*s)->next = *s;
	*s = tmp->next;
	tmp->next = NULL;
	d->ins_nb++;
	if (display == 1)
		dprintf(1, "rra\n");
}

void	rrb(t_data *d, int display)
{
	t_stack		**s;
	t_stack		*tmp;

	s = &d->b;
	if (!(*s) || !((*s)->next))
		return ;
	tmp = before_last(*s);
	go_lstend(*s)->next = *s;
	*s = tmp->next;
	tmp->next = NULL;
	d->ins_nb++;
	if (display == 1)
		dprintf(1, "rrb\n");
}

void	rrr(t_data *d, int display)
{
	rra(d, 0);
	rrb(d, 0);
	d->ins_nb--;
	if (display == 1)
		dprintf(1, "rrr\n");
}
