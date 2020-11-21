/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:50:26 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/21 14:53:45 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_fminus(t_toprint print, int prec)
{
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
		print.structwidth--;
	}
	ft_putstr_fd(print.str, 1);
	while (print.structwidth > 0)
	{
		ft_putchar_fd(' ', 1);
		print.structwidth--;
	}
}

void	ft_fzero(t_toprint print)
{
	if (print.str[0] == '-')
	{
		ft_putchar_fd('-', 1);
		print.str++;
	}
	if (print.format == 'p')
	{
		ft_putstr_fd("0x", 1);
		print.str = print.str + 2;
	}
	while (print.structwidth > 0)
	{
		ft_putchar_fd('0', 1);
		print.structwidth--;
	}
	ft_putstr_fd(print.str, 1);
}

void	ft_noflag(t_toprint print, int prec)
{
	if (print.str[0] == '-')
		print.structwidth--;
	while (print.structwidth > 0 && (print.structwidth + print.len) > prec)
	{
		ft_putchar_fd(' ', 1);
		print.structwidth--;
	}
	if (print.str[0] == '-')
	{
		ft_putchar_fd('-', 1);
		print.str++;
	}
	while (prec > print.len)
	{
		ft_putchar_fd('0', 1);
		prec = prec - 1;
	}
	ft_putstr_fd(print.str, 1);
}
