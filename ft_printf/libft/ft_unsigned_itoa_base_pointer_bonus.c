/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa_base_pointer_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:03:54 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/26 20:49:32 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_length1(unsigned long nb, unsigned long value, int size)
{
	int len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / size;
		len++;
	}
	if (value == 0)
		len = 1;
	len += 2;
	return (len);
}

char	*ft_unsigned_itoa_base_pointer(unsigned long value, char *base,
		int size)
{
	unsigned long	n;
	unsigned long	nb;
	int				len;
	int				i;
	char			*dest;

	n = value;
	i = 0;
	nb = n;
	len = ft_length1(nb, value, size);
	if (!(dest = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = len - 1;
	while (i >= 2)
	{
		dest[i] = base[n % size];
		n = n / size;
		i--;
	}
	dest[i] = 'x';
	dest[i - 1] = '0';
	dest[len] = '\0';
	return (dest);
}
