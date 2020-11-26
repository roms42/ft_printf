/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:19:48 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/26 23:25:08 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_fzero1(t_toprint *print)
{
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
}

void	ft_fzero(t_toprint *print)
{
	int i;

	i = 0;
	ft_fzero1(print);
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
