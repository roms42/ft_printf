/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:21:48 by rberthau          #+#    #+#             */
/*   Updated: 2021/09/18 12:36:23 by roms             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_zeroprec1(t_toprint *print)
{
	if (print->prec == 0 && (print->format == 'd' || print->format == 'i'
			|| print->format == 'u' || print->format == 'x'
			|| print->format == 'X') && print->str[0] == '0')
	{
		return (1);
	}
	return (0);
}

void	ft_noflag1(t_toprint *print)
{
	if ((print->str[0] == '-' && print->format != 's')
		|| (print->str[0] == '-' && print->format == 's' && print->prec == 0))
		print->structwidth--;
	if (ft_zeroprec1(print))
		print->structwidth++;
	while (print->structwidth > 0
		&& (print->structwidth + print->len) > print->prec)
	{
		ft_putchar_fd(' ', 1);
		print->count++;
		print->structwidth--;
	}
	if (print->str[0] == '-' && print->format != 's')
	{
		ft_putchar_fd('-', 1);
		print->count++;
		print->str++;
		if (print->prec > 0)
			print->width++;
	}
}

void	ft_noflag(t_toprint *print)
{
	int	i;

	i = 0;
	ft_noflag1(print);
	while (print->prec > print->len && print->format != 's')
	{
		ft_putchar_fd('0', 1);
		print->count++;
		print->prec = print->prec - 1;
	}
	if (ft_zeroprec1(print))
		return ;
	else
	{
		while (i < print->len)
		{
			ft_putchar_fd(print->str[i], 1);
			print->count++;
			i++;
		}
	}
}
