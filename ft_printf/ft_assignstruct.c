/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assignstruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:35:53 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/27 01:17:04 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			get_index(char *tab, char type)
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

void		ft_percentflag(t_toprint *print, const char *s)
{
	if (!(print->str = malloc(sizeof(char) * 2)))
	{
		print->str = NULL;
		return ;
	}
	print->str[0] = '%';
	print->str[1] = 0;
	s++;
	print->prec = -1;
}

void		ft_assignstruct(t_toprint *print, va_list *list, const char *s)
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
	if (print->format == '%')
		ft_percentflag(print, s);
	else
	{
		index = get_index(tab, print->format);
		print->str = (*tabfunct[index])(list);
	}
	print->len = ft_strlen(print->str);
	print->tmp = print->str;
}
