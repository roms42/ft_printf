/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roms <romain.berthaud812@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:03:29 by roms              #+#    #+#             */
/*   Updated: 2021/09/18 13:24:59 by roms             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	destlen;

	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (srclen);
	if (size <= destlen)
		return (srclen + size);
	while (src[i] && (size - 1 - destlen) && size != 0)
	{
		dst[destlen + i] = src[i];
		i++;
		size--;
	}
	dst[destlen + i] = '\0';
	return (destlen + srclen);
}
