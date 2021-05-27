/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 07:30:03 by abonnel           #+#    #+#             */
/*   Updated: 2021/04/13 11:12:32 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char		*ptr;
	size_t				nb_bytes;

	nb_bytes = count * size;
	ptr = malloc(nb_bytes);
	if (!ptr)
		return (NULL);
	while (nb_bytes)
	{
		ptr[nb_bytes - 1] = 0;
		nb_bytes--;
	}
	return (ptr);
}
