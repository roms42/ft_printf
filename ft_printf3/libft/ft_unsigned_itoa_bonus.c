/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roms <romain.berthaud812@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 15:56:59 by roms              #+#    #+#             */
/*   Updated: 2021/09/18 13:26:10 by roms             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getlen1(unsigned int nb)
{
	int				i;
	unsigned int	n;

	i = 0;
	n = nb;
	if (nb == 0)
		i += 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_createstr1(int *len)
{
	char	*str;

	str = malloc(sizeof(char) * (*len + 1));
	if (!str)
		return (NULL);
	str[*len] = '\0';
	return (str);
}

char	*ft_unsigned_itoa(unsigned int nb)
{
	char			*str;
	unsigned int	n;
	int				len;
	int				i;

	i = 0;
	n = nb;
	len = ft_getlen1(nb);
	str = ft_createstr1(&len);
	while (i <= len - 1 && str != NULL)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}
