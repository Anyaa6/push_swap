/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:08:02 by abonnel           #+#    #+#             */
/*   Updated: 2021/03/29 14:24:06 by abonnel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_malloc(void *ptr, int size)
{
	ptr = malloc(size);
	if (!ptr)
		return (0);
	else
		return (1);
}
