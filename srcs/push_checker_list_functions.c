/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_checker_list_functions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:24:58 by abonnel           #+#    #+#             */
/*   Updated: 2021/05/26 15:19:53 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*newnode(int content)
{
	t_stack			*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!(node))
		return (NULL);
	node->nb = content;
	node->rank = -1;
	node->next = NULL;
	return (node);
}

t_stack	*go_lstend(t_stack *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

t_stack	*before_last(t_stack *s)
{
	if (s)
		while (s->next->next)
			s = s->next;
	return (s);
}

void	lstadd(t_stack **a, t_stack *new)
{
	if (*a)
		go_lstend(*a)->next = new;
	else
		*a = new;
}

void	del_list(t_stack **node, t_data *d)
{
	t_stack		*tmp;

	(void)d;
	while (*node)
	{
		tmp = *node;
		*node = (*node)->next;
		free(tmp);
	}
	*node = NULL;
}
