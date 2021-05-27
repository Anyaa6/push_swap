/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_checker_instructions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:53:33 by abonnel           #+#    #+#             */
/*   Updated: 2021/05/26 15:28:32 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_ins(t_data *d, char *ins)
{
	if (ins[0] == 's' && ins[1] == 'a')
		sa(d, 0);
	else if (ins[0] == 's' && ins[1] == 'b')
		sb(d, 0);
	else if (ins[0] == 's' && ins[1] == 's')
		ss(d, 0);
	else if (ins[0] == 'p' && ins[1] == 'a')
		pa(d, &d->a, &d->b, 0);
	else if (ins[0] == 'p' && ins[1] == 'b')
		pb(d, &d->a, &d->b, 0);
	else if (ins[0] == 'r' && ins[1] == 'a')
		ra(d, 0);
	else if (ins[0] == 'r' && ins[1] == 'b')
		rb(d, 0);
	else if (ins[0] == 'r' && ins[1] == 'r' && ins[2] == 'a')
		rra(d, 0);
	else if (ins[0] == 'r' && ins[1] == 'r' && ins[2] == 'b')
		rrb(d, 0);
	else if (ins[0] == 'r' && ins[1] == 'r' && ins[2] == 'r')
		rrr(d, 0);
	else if (ins[0] == 'r' && ins[1] == 'r')
		rr(d, 0);
}

void	ins_check(t_data *d, char *ins, int i)
{
	if (ins[0] == 's' || ins[0] == 'p' || ins[0] == 'r')
	{
		if (ins[1] == 'a' || ins[1] == 'b' || ins[1] == 's' || ins[1] == 'r')
		{
			if (ins[1] == 's' && (ins[0] != 's' || i != 2))
				error(d, 3);
			if (ins[1] == 'r' && (ins[0] != 'r' && (i != 2 || i != 3)))
				error(d, 3);
			if (i == 3 && !(ins[0] == 'r' && ins[1] == 'r' \
			&& (ins[2] == 'r' || ins[2] == 'a' || ins[2] == 'b')))
				error(d, 3);
		}
		else
			error(d, 3);
	}
	else
		error(d, 3);
}

void	take_ins_and_execute(t_data *d)
{
	char			ins[5];
	int				i;

	i = 0;
	ft_memset(ins, '\0', 5);
	while (read(0, &(ins[i]), 1) > 0)
	{
		if (ins[i] == '\n')
		{
			if (i != 2 && i != 3)
				error(d, 3);
			ins[i + 1] = '\0';
			ins_check(d, ins, i);
			exec_ins(d, ins);
			i = 0;
			ft_memset(ins, '\0', 5);
		}
		else
		{
			if (++i > 3)
				error(d, 3);
		}
	}
	if (ins[0] || ins[1] || ins[2] || ins[3] || ins[4])
		error(d, 3);
}
