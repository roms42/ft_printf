/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:50:26 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/21 19:25:10 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_fminus(t_toprint print, int prec)
{
	int i;

	i = 0;
	if (print.str[0] == '-')
	{
		ft_putchar_fd('-', 1);
		print.str++;
		print.structwidth--;
	}
	while (prec > print.len)
	{
		ft_putchar_fd('0', 1);
		prec = prec - 1;
		print.structwidth = print.structwidth - 1;
	}
	while (i < print.len)
	{
		ft_putchar_fd(print.str[i], 1);
		i++;
	}
	while (print.structwidth > 0)
	{
		ft_putchar_fd(' ', 1);
		print.structwidth--;
	}
}

void	ft_fzero(t_toprint print)
{
	int i;

	i = 0;
	if (print.str[0] == '-')
	{
		ft_putchar_fd('-', 1);
		print.str++;
		print.structwidth = print.structwidth - 1;
	}
	if (print.format == 'p')
	{
		ft_putstr_fd("0x", 1);
		print.str = print.str + 2;
		print.len = print.len - 2;
	}
	while (print.structwidth > 0)
	{
		ft_putchar_fd('0', 1);
		print.structwidth--;
	}
	while (i < print.len)
	{
		ft_putchar_fd(print.str[i], 1);
		i++;
	}
}

void	ft_noflag(t_toprint print, int prec)
{
	int i;

	i = 0;
	if (print.str[0] == '-' && print.format != 's')
		print.structwidth--;
	while (print.structwidth > 0 && (print.structwidth + print.len) > prec)
	{
		ft_putchar_fd(' ', 1);
		print.structwidth--;
	}
	if (print.str[0] == '-' && print.format != 's')
	{
		ft_putchar_fd('-', 1);
		print.str++;
	}
	while (prec > print.len && print.format != 's')
	{
		ft_putchar_fd('0', 1);
		prec = prec - 1;
	}
	while (i < print.len)
	{
		ft_putchar_fd(print.str[i], 1);
		i++;
	}
}
