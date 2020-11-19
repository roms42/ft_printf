/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:37:37 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/19 19:23:55 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

typedef struct	s_toprint
{
	int		structwidth;
	char	format;
	char	*str;
	int		len;
}				t_toprint;

#include "libft/libft.h"
#include <stdarg.h>

int	ft_printf(const char *s, ...);
char	*ft_printf_char(va_list *list);
char	*ft_printf_str(va_list *list);
char	*ft_printf_int(va_list *list);
char	*ft_printf_unsigned(va_list *list);
char	*ft_printf_hexalow(va_list *list);
char	*ft_printf_hexaup(va_list *list);
char	*ft_printf_pointer(va_list *list);
void	ft_fminus(t_toprint print, int prec);
void	ft_fzero(t_toprint print);
void	ft_noflag(t_toprint print, int prec);

#endif
