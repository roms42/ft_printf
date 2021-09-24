/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtypes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:29:27 by rberthau          #+#    #+#             */
/*   Updated: 2021/09/18 12:43:41 by roms             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_printf_hexalow(va_list *list)
{
	unsigned int	num;
	char			*s;

	num = va_arg(*list, int);
	if (num < 0)
		num += 4294967295 + 1;
	s = ft_unsigned_itoa_base(num, "0123456789abcdef", 16);
	return (s);
}

char	*ft_printf_hexaup(va_list *list)
{
	unsigned int	num;
	char			*s;

	num = va_arg(*list, int);
	if (num < 0)
		num += 4294967295 + 1;
	s = ft_unsigned_itoa_base(num, "0123456789ABCDEF", 16);
	return (s);
}

char	*ft_printf_pointer(va_list *list)
{
	unsigned long	p;
	char			*s;

	p = va_arg(*list, unsigned long);
	s = ft_unsigned_itoa_base_pointer(p, "0123456789abcdef", 16);
	return (s);
}
