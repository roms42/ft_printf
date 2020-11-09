/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:12:12 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/09 16:24:02 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <stdarg.h>

void	ft_printf_char(va_list *list)
{
	char	c;

	c = va_arg(*list, int);
	write(1, &c, 1);
}

void	ft_printf_str(va_list *list)
{
	char	*str;

	str = va_arg(*list, char *);
	ft_putstr_fd(str, 1);
}

void	ft_printf_int(va_list *list)
{
	int num;

	num = va_arg(*list, int);
	ft_putnbr_fd(num, 1);
}

int	get_index(char *tab, type)
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

int	ft_printf(const char *s, ...)
{
	va_list	list;
	char	*tab;
	void	(*tabfunct[3])(va_list*);
	int i;
	int index;

	tab = "scd";
	tabfunct = {&ft_printf_char, &ft_printf_str, &ft_printf_int};
	va_start(list, s);
	while (s[i])
	{
		if (i != 0 && s[i - 1] == '%')
		{
			index = get_index(tab, s[i]);
			(*tabfunct[index])(list);
		}
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	return (i);
}

int	main(int ac, const char *av)
{

}
