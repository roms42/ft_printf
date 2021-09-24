/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roms <romain.berthaud812@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 15:56:59 by roms              #+#    #+#             */
/*   Updated: 2021/09/18 13:30:08 by roms             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getlen(int nb)
{
	int		i;
	long	n;

	i = 0;
	n = nb;
	if (nb < 0)
		n = -n;
	if (nb == 0)
		i += 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_createstr(int nb, long *n, int *len, int *i)
{
	char	*str;

	if (nb < 0)
	{
		*len += 1;
		str = malloc(sizeof(char) * (*len + 1));
		if (!str)
			return (NULL);
		str[*i] = '-';
		*i += 1;
		*n *= -1;
	}
	else
	{
		str = malloc(sizeof(char) * (*len + 1));
		if (!str)
			return (NULL);
	}
	str[*len] = '\0';
	return (str);
}

char	*ft_itoa(int nb)
{
	char	*str;
	long	n;
	int		len;
	int		i;

	i = 0;
	n = nb;
	len = ft_getlen(nb);
	str = ft_createstr(nb, &n, &len, &i);
	while (i <= len - 1 && str != NULL)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}
