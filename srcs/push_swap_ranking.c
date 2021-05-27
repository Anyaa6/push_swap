/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ranking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:40:08 by abonnel           #+#    #+#             */
/*   Updated: 2021/05/26 15:30:03 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_rank_table(t_data *d)
{
	int			i;
	t_stack		*cpy;
	int			*tab;

	tab = (int *)calloc(d->nb_arg, sizeof(int));
	if (!tab)
		error(d, 0);
	cpy = d->a;
	i = 0;
	while (cpy)
	{
		tab[i] = cpy->nb;
		i++;
		cpy = cpy->next;
	}
	i = 0;
	return (tab);
}

void	sort_int_tab(int *tab, int size)
{
	int			a;
	int			b;
	int			temp_number;

	a = -1;
	b = a + 1;
	while (++a <= size - 2)
	{
		while (++b <= size - 1)
		{
			if (tab[a] > tab[b])
			{
				temp_number = tab[b];
				tab[b] = tab[a];
				tab[a] = temp_number;
			}
		}
		b = a + 1;
	}
}

void	convert_nb_to_rank(t_data *d, int *index)
{
	int			i;
	t_stack		*cpy;

	cpy = d->a;
	i = 0;
	while (cpy)
	{
		i = 0;
		while (cpy->nb != index[i])
			i++;
		cpy->rank = i;
		cpy = cpy->next;
	}
}

void	nb_to_rank_set_pivot(t_data *d)
{
	int			*ranks;

	ranks = create_rank_table(d);
	sort_int_tab(ranks, d->nb_arg);
	convert_nb_to_rank(d, ranks);
	free(ranks);
}
