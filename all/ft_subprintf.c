/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:49:29 by rberthau          #+#    #+#             */
/*   Updated: 2021/09/18 12:15:30 by roms             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_allflags(t_toprint *print, int k, const char *s)
{
	if (print->format == 'p' && print->prec > print->len)
	{
		print->structwidth = print->prec - print->len + 2;
		ft_fzero(print);
	}
	else if ((k && (s[0] == '-' || s[1] == '-')) || print->width < 0)
	{
		if (print->width < 0)
			print->width *= -1;
		ft_fminus(print);
	}
	else if ((k && s[0] == '0' && print->prec < 0 && print->str[0] != '0')
		|| (k && s[0] == '0' && print->prec < 0 && print->str[0] == '0'
			&& print->str[1] == 0 && print->width > 1))
		ft_fzero(print);
	else if (k && s[0] == '0' && print->format == 's')
		ft_fzero(print);
	else
		ft_noflag(print);
}

void	ft_subprintf1(t_toprint *print, const char *s, int *i, int *k)
{
	*i = 0;
	*k = 0;
	print->count = 0;
	print->prec = -1;
	print->width = 0;
	if (*s == ' ' && s[1] != ' ')
	{
		ft_putchar_fd(' ', 1);
		print->count++;
		s++;
		print->width--;
	}
	while (*s == ' ')
		s++;
	while (s[*k] == '-' || s[*k] == '0')
		*k += 1;
	while ((s[*i + *k] >= '0' && s[*i + *k] <= '9') || s[*i + *k] == '*')
		*i += 1;
}

void	ft_subprintf2(t_toprint *print, int *i, int *l, const char *s)
{
	print->format = s[*i + *l];
	if (l == 0 && print->format == 's' && print->prec == 1)
		print->prec = 0;
	if (print->prec < -1)
		print->prec = -1;
}

void	ft_subprintf3(t_toprint *print, int j)
{
	if (print->str[2] == '0' && print->prec == 0 && print->format == 'p'
		&& print->width >= print->len)
		print->width++;
	if ((print->width <= 0 || print->width < print->len)
		&& print->format == 'p' && j == 1)
		print->width = print->len;
	if (print->width < 0)
		print->structwidth = (print->width * -1) - print->len;
	else
		print->structwidth = print->width - print->len;
	if ((print->width > print->prec || (print->width * -1) > print->prec)
		&& print->str[0] == '-' && print->prec != -1)
	{
		if (print->format != 's' || (print->format == 's' && print->prec == 0))
			print->structwidth++;
	}
}

int	ft_subprintf(const char *s, va_list *list)
{
	int			i;
	int			k;
	t_toprint	print;
	int			l;
	int			j;

	l = 0;
	ft_subprintf1(&print, s, &i, &k);
	if (i || s[k] == '*')
		print.width = print.width + ft_getwidth(&i, &k, s, list);
	i = i + k;
	if (s[i] == '.')
		print.prec = ft_getprecision(&i, &l, list, s);
	if (!s[i + l])
		return (0);
	ft_subprintf2(&print, &i, &l, s);
	j = ft_padding(&print, list, s);
	ft_subprintf3(&print, j);
	ft_allflags(&print, k, s);
	free(print.tmp);
	return (print.count);
}
