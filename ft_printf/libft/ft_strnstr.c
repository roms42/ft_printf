/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roms <romain.berthaud812@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:47:35 by roms              #+#    #+#             */
/*   Updated: 2020/10/20 19:24:00 by roms             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_findneedle(const char *big, const char *little, size_t len)
{
	size_t i;

	i = 0;
	while (big[i] == little[i] && little[i] && len - i > 0)
		i++;
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t littlelen;

	littlelen = ft_strlen(little);
	if (!big && !little)
		return (0);
	if (*little == 0)
		return ((char*)(big));
	while (*big && len > 0)
	{
		i = ft_findneedle(big, little, len);
		if (i == littlelen)
			return ((char*)(big));
		if (i)
		{
			big += i - 1;
			len -= i - 1;
		}
		big++;
		len--;
	}
	return (NULL);
}
