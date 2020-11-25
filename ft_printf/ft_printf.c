/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:41:38 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/25 22:19:44 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	get_index(char *tab, char type)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == type)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_allflags(t_toprint *print, int k, const char *s, int prec)
{
	if (print->format == 'p' && prec > print->len)
	{
		print->structwidth = prec - print->len + 2;
		ft_fzero(print);
	}
	else if ((k && (s[0] == '-' || s[1] == '-')) || print->width < 0)
	{
		if (print->width < 0)
			print->width *= -1;
		ft_fminus(print, prec);
	}
	else if ((k && s[0] == '0' && prec < 0 && print->str[0] != '0')
			|| (k && s[0] == '0' && prec < 0 && print->str[0] == '0'
				&& print->str[1] == 0 && print->width > 1))
		ft_fzero(print);
	else if (k && s[0] == '0' && print->format == 's')
		ft_fzero(print);
	else
		ft_noflag(print, prec);
}

int		ft_getwidth(int *i, int *k, const char *s, va_list *list)
{
	int j;
	char *tmp;
	int width;

	tmp = malloc(sizeof(char) * (*i + 1));
	if (!tmp)
		return (0);
	j = 0;
	while (j < *i)
	{
		tmp[j] = s[j + *k];
		j++;
	}
	tmp[j] = 0;
	width = ft_atoi(tmp);
	if (s[*k] == '*')
		width = va_arg(*list, int);
	free (tmp);
	return (width);
}

int		ft_getprecision(int *i, int *l, va_list *list, const char *s)
{
	int j;
	int prec;
	char *tmp;

	j = 0;
	prec = 1;
	*i = *i + 1;
	if ((s[*i] < '0' || s[*i] > '9') && s[*i] != '*')
		prec = 0;
	else if (s[*i] == '*')
	{
		prec = va_arg(*list, int);
		*l = *l + 1;
	}
	else
	{
		while (s[*i + *l] >= '0' && s[*i + *l] <= '9')
			*l = *l + 1;
		if (*l)
		{
			tmp = malloc(sizeof(char) * (*l + 1));
			if (!tmp)
				return (0);
			while (j < *l)
			{
				tmp[j] = s[j + *i];
				j++;
			}
			tmp[j] = 0;
			prec = ft_atoi(tmp);
			free (tmp);
		}
	}
	return (prec);
}

void	ft_assignstruct(t_toprint *print, va_list *list, int *prec, const char *s)
{
	char		*(*tabfunct[8])(va_list*);
	char		*tab;
	int			index;
	int			j;

	j = 1;
	tab = "csdiuxXp%";
	tabfunct[0] = &ft_printf_char;
   	tabfunct[1] = &ft_printf_str;
	tabfunct[2] = &ft_printf_int;
	tabfunct[3] = &ft_printf_int;
	tabfunct[4] = &ft_printf_unsigned;
	tabfunct[5] = &ft_printf_hexalow;
	tabfunct[6] = &ft_printf_hexaup;
	tabfunct[7] = &ft_printf_pointer;

	if (print->format == '%')
	{
		if (!(print->str = malloc(sizeof(char) * 2)))
		{
			print->str = NULL;
			return ;
		}
		print->str[0] = '%';
		print->str[1] = 0;
		s++;
	}
	else
	{
		index = get_index(tab, print->format);
		print->str = (*tabfunct[index])(list);
	}
	print->len = ft_strlen(print->str);
	if (print->width < 0)
	{
		if ((print->width * -1) >= print->len)
			j = 0;
	}
	if ((print->width > *prec || (print->width * -1) > *prec) && print->str[0] == '-' && *prec != -1 && print->format != 's')
	{
		if (print->width > 0)
			print->width--;
		else
			print->width++;
	}
	if (print->str[0] == 0 && print->format == 'c')
		print->len = 1;
	if ((print->str[0] == 0 || print->str[0] == '0') && *prec == 0
			&& print->format != 's'&& print->format != 'c'
		   	&& print->format != 'p' && print->width == 0)
		print->width--;
	if ((print->width <= 0 || print->width < print->len)
			&& print->format != 'p'
			&& print->format != 's'
			&& (print->str[0] == 0
			|| print->str[0] == '0')
			&& j == 1)
		print->width = print->width + print->len;
	else if (print->len > *prec && *prec != -1
			&& print->format != 'c'
			&& print->format != 's'
			&& print->width < print->len
			&& print->str[0] == '-'
			&& j == 1)
		print->width = print->len - 1;
	else if ((print->width <= 0 || print->width < print->len)
			&& print->format != 's'
			&& j == 1)
		print->width = print->len;
	if (print->str[2] == '0' && *prec == 0 && print->format == 'p')
	{
		print->len--;
		print->width--;
	}
	if (print->str[0] == '-' && print->format != 's')
		print->len--;
	if (print->format == 's' && *prec < print->len && *prec > -1)
		print->len = *prec;
	if (print->format == 's' && *prec > print->len && print->width != 0)
		*prec = print->len;
	/*if ((print->width <= 0 || print->width < print->len)
			&& print->format == 's' && j == 1 && *prec == -1)
		print->width = print->len;*/
}

int	ft_subprintf(const char *s, va_list *list)
{
	int			i;
	int			k;
	t_toprint	print;
	int			prec;
	int			l;

	i = 0;
	k = 0;
	l = 0;
	print.count = 0;
	prec = -1;
	print.width = 0;
	if (*s == ' ' && s[1] != ' ')
	{
		ft_putchar_fd(' ', 1);
		print.count++;
		s++;
		print.width = print.width - 1;
	}
	while (*s == ' ')
		s++;
	while (s[k] == '-' || s[k] == '0')
		k++;
	while ((s[i + k] >= '0' && s[i + k] <= '9') || s[i + k] == '*')
		i++;
	if (i || s[k] == '*')
		print.width = print.width + ft_getwidth(&i, &k, s, list);
	i = i + k;
	if (s[i] == '.')
		prec = ft_getprecision(&i, &l, list, s);
	if (!s[i + l])
		return (0);
	print.format = s[i + l];
	if (l == 0 && print.format == 's' && prec == 1)
		prec = 0;
	if (prec < -1)
		prec = -1;
	ft_assignstruct(&print, list, &prec, s);
	if (print.str[2] == '0' && prec == 0 && print.format == 'p'
			&& print.width > print.len)
		print.width++;
	if (print.width < 0)
		print.structwidth = (print.width * -1) - print.len;
	else
		print.structwidth = print.width - print.len;
	if ((print.width > prec || (print.width * -1) > prec)
			&& print.str[0] == '-' && prec != -1)
	{
		if (print.format != 's' || (print.format == 's' && prec == 0))
		{
			print.structwidth++;
			if (print.width == 1)
				print.width = 2;
		}
	}
	if (prec > print.width && print.format != 's'
			&& print.format != 'c' && print.width >= 0)
		print.width = prec;
	ft_allflags(&print, k, s, prec);
	return (print.count);
}

int		ft_getinstructs(const char *s, int *n)
{
	int i;

	i = 0;
	if (s[i] == ' ' && s[i + 1] != ' ')
	{
		i++;
		*n += 1;
	}
	while (s[i] == ' ')
		i++;
	while (s[i] == '-' || s[i] == '0' || (s[i] > '0' && s[i] <= '9')
			|| s[i] == '.' || s[i] == '*')
		i++;
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		j;
	int		n;

	n = 0;
	j = 0;
	va_start(list, s);
	while (*s)
	{
		if (*s == '%')
		{
			/*if (j > 0)
			{
				if (s[-1] == '%' && s[1] != 0)
				{
					s++;
					ft_putchar_fd(*s, 1);
					write(1, &c, 1);
					s++;
					n++;
					j = 0;
				}
				else
				{
					j = 1;
					s++;
					if (*s)
					{
						i = 0;
						n += ft_subprintf(s, &list);
						i =	ft_getinstructs(s, &n);
						s += i;
						if (*s == 'd' || *s == 'i' || *s == 'u' || *s == 'x'
								|| *s == 'X' || *s == 'p' || *s == 'c'
								|| *s == 's')
							s += 1;
					}
				}
			}
			else
			{*/
			j = 1;
			s++;
			if (*s)
			{
				i = 0;
				n += ft_subprintf(s, &list);
				i =	ft_getinstructs(s, &n);
				s += i;
				if (*s == 'd' || *s == 'i' || *s == 'u' || *s == 'x'
						|| *s == 'X' || *s == 'p' || *s == 'c'
						|| *s == 's' || *s == '%')
					s += 1;
			}
		}
		else
		{
			ft_putchar_fd(*s, 1);
			s++;
			n++;
		}
	}
	return (n);
}
