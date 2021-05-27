/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_checker_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:40:41 by abonnel           #+#    #+#             */
/*   Updated: 2021/05/27 10:42:57 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_memory(t_data *d)
{
	if (d->a)
		del_list(&(d->a), d);
	if (d->b)
		del_list(&(d->b), d);
}

void	error(t_data *d, int err)
{
	write(2, "Error\n", 6);
	if (err == 0)
		dprintf(1, "Malloc issue");
	else if (err == 1)
		dprintf(1, "Arguments have duplicate or are not integers");
	else if (err == 2)
		dprintf(1, "Argument is bigger or smaller than an integer");
	else if (err == 3)
	{
		dprintf(1, "Instruction wrong format / does not exist / ");
		dprintf(1, "not finished");
	}
	write(1, "\n", 1);
	free_memory(d);
	exit(0);
}
