/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa_base_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:03:54 by rberthau          #+#    #+#             */
/*   Updated: 2021/09/18 13:22:38 by roms             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_length(unsigned long nb, unsigned long value, int size)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / size;
		len++;
	}
	if (value == 0)
		len = 1;
	return (len);
}

char	*ft_unsigned_itoa_base(unsigned long value, char *base, int size)
{
	unsigned long	n;
	unsigned long	nb;
	int				len;
	int				i;
	char			*dest;

	n = value;
	i = 0;
	nb = n;
	len = ft_length(nb, value, size);
	dest = malloc(sizeof(char) * len + 1);
	if (!(dest))
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		dest[i] = base[n % size];
		n = n / size;
		i--;
	}
	dest[len] = '\0';
	return (dest);
}
