/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:41:38 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/21 16:35:26 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

void	ft_allflags(t_toprint print, int k, const char *s, int prec)
{
	if (k && s[0] == '-')
		ft_fminus(print, prec);
	else if (k && s[0] == '0' && prec == 0)
		ft_fzero(print);
	else
		ft_noflag(print, prec);
}

int		ft_getwidth(int *i, int *k, const char *s, va_list *list)
{
	int j;
	char *tmp;
	int width;

	if (s[*k] == '*')
	{
		width = va_arg(*list, int);
		return (width);
	}
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
	if (s[*i] == '*')
	{
		prec = va_arg(*list, int);
		*l = *l + 1;
	}
	else
	{
		while (s[*i + *l] > '0' && s[*i + *l] <= '9')
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

void	ft_assignstruct(t_toprint *print, va_list *list)
{
	char		*(*tabfunct[8])(va_list*);
	char		*tab;
	int			index;

	tab = "csdiuxXp";
	tabfunct[0] = &ft_printf_char;
   	tabfunct[1] = &ft_printf_str;
	tabfunct[2] = &ft_printf_int;
	tabfunct[3] = &ft_printf_int;
	tabfunct[4] = &ft_printf_unsigned;
	tabfunct[5] = &ft_printf_hexalow;
	tabfunct[6] = &ft_printf_hexaup;
	tabfunct[7] = &ft_printf_pointer;

	index = get_index(tab, print->format);
	print->str = (*tabfunct[index])(list);
	print->len = ft_strlen(print->str);
	if (print->str[0] == '-')
		print->len--;
}

int	ft_subprintf(const char *s, va_list *list)
{
	int			i;
	int			k;
	int			width;
	t_toprint	print;
	int			prec;
	int			l;

	i = 0;
	k = 0;
	l = 0;
	prec = 0;
	width = 0;
	if (s[k] == '-' || s[k] == '0')
		k++;
	while ((s[i + k] >= '0' && s[i + k] <= '9') || s[i + k] == '*')
		i++;
	if (i || s[k] == '*')
		width = ft_getwidth(&i, &k, s, list);
	i = i + k;
	if (s[i] == '.')
		prec = ft_getprecision(&i, &l, list, s);
	print.format = s[i + l];
	ft_assignstruct(&print, list);
	print.structwidth = width - print.len;
	ft_allflags(print, k, s, prec);
	return (width);
}

int		ft_getinstructs(const char *s)
{
	int i;

	i = 0;
	while (s[i] == '-' || s[i] == '0' || (s[i] > '0' && s[i] <= '9')
			|| s[i] == '.' || s[i] == '*')
		i++;
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		n;

	n = 0;
	va_start(list, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			n++;
			i = 0;
			n += ft_subprintf(s, &list);
			i = ft_getinstructs(s);
			s += (i + 1);
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
