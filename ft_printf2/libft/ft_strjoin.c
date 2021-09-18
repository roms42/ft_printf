/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roms <romain.berthaud812@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:12:31 by roms              #+#    #+#             */
/*   Updated: 2020/11/16 15:10:33 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_getsize(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	dstlen;

	s1len = 0;
	s2len = 0;
	while (s1[s1len])
		s1len++;
	while (s2[s2len])
		s2len++;
	dstlen = s1len + s2len;
	return (dstlen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	dstlen;
	size_t	i;

	i = 0;
	dstlen = ft_getsize(s1, s2);
	dst = malloc(sizeof(char) * (dstlen + 1));
	if (!dst)
		return (NULL);
	while (*s1)
	{
		dst[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		dst[i++] = *s2;
		s2++;
	}
	dst[dstlen] = 0;
	return (dst);
}
