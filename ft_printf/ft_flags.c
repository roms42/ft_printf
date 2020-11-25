/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:50:26 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/25 20:27:18 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		ft_zeroprec(t_toprint *print, int prec)
{
	if (prec == 0 && (print->format == 'd' || print->format == 'i'
				|| print->format == 'u' || print->format == 'x'
				|| print->format == 'X') && print->str[0] == '0')
	{
		//print->width = print->width - 1;
		return (1);
	}
	return (0);
}

void	ft_fminus(t_toprint *print, int prec)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (print->str[0] == '-' && print->format != 's')
	{
		ft_putchar_fd('-', 1);
		print->count++;
		print->str++;
		print->structwidth--;
		if (prec > 0)
			print->width++;
	}
	while (prec > print->len && print->format != 's')
	{
		ft_putchar_fd('0', 1);
		print->count++;
		prec = prec - 1;
		print->structwidth = print->structwidth - 1;
	}
	if (ft_zeroprec(print, prec))
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
	if (print->str[0] == '-' && print->format == 's' && prec == 0)
		print->structwidth--;

	while (print->structwidth > 0)
	{
		ft_putchar_fd(' ', 1);
		print->count++;
		print->structwidth--;
	}
}

void	ft_fzero(t_toprint *print)
{
	int i;

	i = 0;
	if (print->str[0] == '-')
	{
		ft_putchar_fd('-', 1);
		print->count++;
		print->str++;
		print->structwidth = print->structwidth - 1;
	}
	if (print->format == 'p')
	{
		ft_putstr_fd("0x", 1);
		print->count += 2;
		print->str = print->str + 2;
		print->len = print->len - 2;
		print->width += 2;
	}
	while (print->structwidth > 0)
	{
		ft_putchar_fd('0', 1);
		print->count++;
		print->structwidth--;
	}
	while (i < print->len)
	{
		ft_putchar_fd(print->str[i], 1);
		print->count++;
		i++;
	}
}

void	ft_noflag(t_toprint *print, int prec)
{
	int i;

	i = 0;
	if ((print->str[0] == '-' && print->format != 's') || (print->str[0] == '-' && print->format == 's' && prec == 0))
		print->structwidth--;
	if (ft_zeroprec(print, prec))
		print->structwidth++;
	while (print->structwidth > 0 && (print->structwidth + print->len) > prec)
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
		if (prec > 0)
			print->width++;
	}
	while (prec > print->len && print->format != 's')
	{
		ft_putchar_fd('0', 1);
		print->count++;
		prec = prec - 1;
	}
	if (ft_zeroprec(print, prec))
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
