/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:37:37 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/27 01:15:31 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_toprint
{
	int		structwidth;
	char	format;
	char	*str;
	int		len;
	int		width;
	int		prec;
	int		count;
	char	*tmp;
}				t_toprint;

int				ft_printf(const char *s, ...);
char			*ft_printf_char(va_list *list);
char			*ft_printf_str(va_list *list);
char			*ft_printf_int(va_list *list);
char			*ft_printf_unsigned(va_list *list);
char			*ft_printf_hexalow(va_list *list);
char			*ft_printf_hexaup(va_list *list);
char			*ft_printf_pointer(va_list *list);
void			ft_fminus(t_toprint *print);
void			ft_fzero(t_toprint *print);
void			ft_noflag(t_toprint *print);
void			ft_fminus(t_toprint *print);
void			ft_fzero(t_toprint *print);
void			ft_noflag(t_toprint *print);
int				ft_getwidth(int *i, int *k, const char *s, va_list *list);
int				ft_getprecision(int *i, int *l, va_list *list, const char *s);
void			ft_assignstruct(t_toprint *print, va_list *list,
		const char *s);
int				ft_padding(t_toprint *print, va_list *list, const char *s);
int				ft_subprintf(const char *s, va_list *list);

#endif
