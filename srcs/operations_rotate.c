/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:33:44 by abonnel           #+#    #+#             */
/*   Updated: 2021/05/26 15:18:52 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *d, int display)
{
	t_stack		**s;
	t_stack		*tmp;

	s = &(d->a);
	if (!(*s) || !((*s)->next))
		return ;
	tmp = go_lstend(*s);
	tmp->next = *s;
	*s = (*s)->next;
	tmp->next->next = NULL;
	d->ins_nb++;
	if (display == 1)
		dprintf(1, "ra\n");
}

void	rb(t_data *d, int display)
{
	t_stack		**s;
	t_stack		*tmp;

	s = &d->b;
	if (!(*s) || !((*s)->next))
		return ;
	tmp = go_lstend(*s);
	tmp->next = *s;
	*s = (*s)->next;
	tmp->next->next = NULL;
	d->ins_nb++;
	if (display == 1)
		dprintf(1, "rb\n");
}

void	rr(t_data *d, int display)
{
	ra(d, 0);
	rb(d, 0);
	d->ins_nb--;
	if (display == 1)
		dprintf(1, "rr\n");
}
