/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:41:38 by rberthau          #+#    #+#             */
/*   Updated: 2021/09/18 12:01:29 by roms             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_getinstructs(const char *s, int *n)
{
	int	i;

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

const char	*ft_printf1(const char *s, int *n, va_list *list)
{
	int	i;

	i = 0;
	s += 1;
	if (*s)
	{
		i = 0;
		*n = *n + ft_subprintf(s, list);
		i = ft_getinstructs(s, n);
		s += i;
		if (*s == 'd' || *s == 'i' || *s == 'u' || *s == 'x'
			|| *s == 'X' || *s == 'p' || *s == 'c'
			|| *s == 's' || *s == '%')
			s += 1;
	}
	return (s);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		n;

	n = 0;
	va_start(list, s);
	while (*s)
	{
		if (*s == '%')
		{
			s = ft_printf1(s, &n, &list);
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
