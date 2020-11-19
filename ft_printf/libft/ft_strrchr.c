/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roms <romain.berthaud812@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:30:49 by roms              #+#    #+#             */
/*   Updated: 2020/11/16 14:28:33 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int slen;

	if (!s)
		s = NULL;
	slen = ft_strlen(s);
	s += slen;
	while (*s != c && slen != 0)
	{
		s--;
		slen--;
	}
	if (slen == 0 && *s != c)
		return (NULL);
	return ((char*)(s));
}
