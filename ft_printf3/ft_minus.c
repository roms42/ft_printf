/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:14:43 by rberthau          #+#    #+#             */
/*   Updated: 2021/09/18 12:29:26 by roms             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_zeroprec(t_toprint *print)
{
	if (print->prec == 0 && (print->format == 'd' || print->format == 'i'
			|| print->format == 'u' || print->format == 'x'
			|| print->format == 'X') && print->str[0] == '0')
	{
		return (1);
	}
	return (0);
}

void	ft_minus1(t_toprint *print)
{
	if (print->str[0] == '-' && print->format != 's')
	{
		ft_putchar_fd('-', 1);
		print->count++;
		print->str++;
		print->structwidth--;
		if (print->prec > 0)
			print->width++;
	}
	while (print->prec > print->len && print->format != 's')
	{
		ft_putchar_fd('0', 1);
		print->count++;
		print->prec = print->prec - 1;
		print->structwidth = print->structwidth - 1;
	}
}

void	ft_fminus(t_toprint *print)
{
	int	i;

	i = 0;
	ft_minus1(print);
	if (ft_zeroprec(print))
		print->structwidth = print->structwidth + 1;
	else
	{
		while (i < print->len)
		{
			ft_putchar_fd(print->str[i], 1);
			print->count++;
			i++;
		}
	}
	if (print->str[0] == '-' && print->format == 's' && print->prec == 0)
		print->structwidth--;
	while (print->structwidth > 0)
	{
		ft_putchar_fd(' ', 1);
		print->count++;
		print->structwidth--;
	}
}
