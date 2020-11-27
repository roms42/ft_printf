/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtypes2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:27:47 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/27 01:37:18 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_printf_char(va_list *list)
{
	char	c;
	char	*s;
	int		i;

	i = 0;
	c = va_arg(*list, int);
	s = malloc(sizeof(char) * 2);
	if (!s)
		return (NULL);
	s[i] = c;
	s[i + 1] = 0;
	return (s);
}

char	*ft_printf_str(va_list *list)
{
	char	*str;
	char	*tmp;

	str = va_arg(*list, char *);
	if (str == NULL)
	{
		free(str);
		if (!(str = malloc(sizeof(char) * 7)))
			return (NULL);
		str = "(null)";
	}
	tmp = ft_strdup(str);
	return (tmp);
}

char	*ft_printf_int(va_list *list)
{
	int		num;
	char	*s;

	num = va_arg(*list, int);
	s = ft_itoa(num);
	return (s);
}

char	*ft_printf_unsigned(va_list *list)
{
	unsigned	num;
	char		*s;

	num = va_arg(*list, int);
	if (num < 0)
		num += 4294967295 + 1;
	s = ft_unsigned_itoa(num);
	return (s);
}
