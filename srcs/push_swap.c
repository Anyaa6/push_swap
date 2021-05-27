/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:39:39 by abonnel           #+#    #+#             */
/*   Updated: 2021/05/27 12:39:32 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_struct(t_data *d, int argc)
{
	d->a = NULL;
	d->b = NULL;
	d->nb_arg = argc - 1;
	d->nb_in_a = d->nb_arg;
	d->nb_in_b = 0;
	d->ins_nb = 0;
}

//ARG=`ruby -e "puts (0..500).to_a.shuffle.join(' ')"` ; ./push_swap $ARG

int	main(int argc, char **argv)
{
	t_data		d;

	if (argc == 1 || (argc == 2 && !(argv[1][0])))
		exit(0);
	init_struct(&d, argc);
	check_arg(&d, argv, argc);
	if (is_sorted(&d) == 1)
	{
		free_memory(&d);
		exit(0);
	}
	nb_to_rank_set_pivot(&d);
	if (d.nb_arg >= 2 && d.nb_arg <= 5)
		sort_short_stacks(&d);
	else
		sort_stack_iterations(&d);
	free_memory(&d);
	return (0);
}
