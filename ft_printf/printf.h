/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:37:37 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/17 18:30:42 by rberthau         ###   ########.fr       */
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

#endif
