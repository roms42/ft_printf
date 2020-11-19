/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roms <romain.berthaud812@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 22:06:02 by roms              #+#    #+#             */
/*   Updated: 2020/11/16 15:25:27 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_overlap(void *dest, const void *src, size_t n)
{
	if (src > dest)
	{
		if (n > (size_t)(src - dest))
			return (1);
	}
	if (src < dest)
	{
		if (n > (size_t)(dest - src))
			return (1);
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	int		overlap;

	i = 0;
	if (!src && !dest)
		return (NULL);
	overlap = ft_overlap(dest, src, n);
	if (overlap)
	{
		dest = ft_memmove(dest, src, n);
		return (dest);
	}
	while (i < n)
	{
		*(char*)(dest + i) = *(char*)(src + i);
		i++;
	}
	return (dest);
}
