/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:39:39 by abonnel           #+#    #+#             */
/*   Updated: 2021/05/26 15:06:11 by abonnel          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data		d;

	if (argc == 1)
		exit(0);
	init_struct(&d, argc);
	check_arg(&d, argv, argc);
	take_ins_and_execute(&d);
	if (is_sorted(&d) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_memory(&d);
	return (0);
}
