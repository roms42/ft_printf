/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:40:04 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/26 23:40:54 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_padding1(t_toprint *print)
{
	if ((print->width > print->prec || (print->width * -1) > print->prec)
			&& print->str[0] == '-'
			&& print->prec != -1 && print->format != 's')
	{
		if (print->width > 0)
			print->width--;
		else
			print->width++;
	}
	if (print->str[0] == 0 && print->format == 'c')
		print->len = 1;
	if ((print->str[0] == 0 || print->str[0] == '0') && print->prec == 0
			&& print->format != 's' && print->format != 'c'
			&& print->width == 0)
		print->width--;
}

void		ft_padding2(t_toprint *print, int *j)
{
	if ((print->width <= 0 || print->width < print->len)
			&& print->format != 'p'
			&& print->format != 's'
			&& (print->str[0] == 0
			|| print->str[0] == '0')
			&& *j == 1)
		print->width = print->width + print->len;
	else if (print->len > print->prec && print->prec != -1
			&& print->format != 'c'
			&& print->format != 's'
			&& print->width < print->len
			&& print->str[0] == '-'
			&& *j == 1)
		print->width = print->len - 1;
	else if ((print->width <= 0 || print->width < print->len)
			&& print->format != 's'
			&& print->format != 'p'
			&& *j == 1)
		print->width = print->len;
}

void		ft_padding3(t_toprint *print)
{
	if (print->str[2] == '0' && print->prec == 0 && print->format == 'p')
	{
		print->len--;
		if (print->width >= 0)
			print->width--;
	}
	if (print->str[0] == '-' && print->format != 's')
		print->len--;
	if (print->format == 's' && print->prec < print->len && print->prec > -1)
		print->len = print->prec;
	if (print->format == 's' && print->prec > print->len && print->width != 0)
		print->prec = print->len;
}

int			ft_padding(t_toprint *print, va_list *list, const char *s)
{
	int	j;

	j = 1;
	ft_assignstruct(print, list, s);
	if (print->width < 0)
	{
		if ((print->width * -1) >= print->len)
			j = 0;
	}
	ft_padding1(print);
	ft_padding2(print, &j);
	ft_padding3(print);
	return (j);
}
