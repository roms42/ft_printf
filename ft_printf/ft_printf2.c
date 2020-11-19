/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:41:38 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/19 11:57:56 by rberthau         ###   ########.fr       */
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

	str = va_arg(*list, char *);
	return (str);
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

char	*ft_printf_hexalow(va_list *list)
{
	unsigned	num;
	char		*s;

	num = va_arg(*list, int);
	if (num < 0)
		num += 4294967295 + 1;
	s = ft_unsigned_itoa_base(num, "0123456789abcdef", 16);
	return (s);
}

char	*ft_printf_hexaup(va_list *list)
{
	unsigned	num;
	char		*s;

	num = va_arg(*list, int);
	if (num < 0)
		num += 4294967295 + 1;
	s = ft_unsigned_itoa_base(num, "0123456789ABCDEF", 16);
	return (s);
}

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

void	ft_flags(t_toprint print, int *k, const char *s, int *prec)
{
	if (*k && s[0] == '-')
	{
		if (print.str[0] == '-')
		{
			ft_putchar_fd('-', 1);
			print.str++;
			print.structwidth--;
		}
		while (*prec > print.len)
		{
			ft_putchar_fd('0', 1);
			*prec = *prec - 1;
			print.structwidth--;
		}
		ft_putstr_fd(print.str, 1);
		while (print.structwidth > 0)
		{
			ft_putchar_fd(' ', 1);
			print.structwidth--;
		}
	}
	else if (*k && s[0] == '0' && *prec == 0)
	{
		if (print.str[0] == '-')
		{
			ft_putchar_fd('-', 1);
			print.str++;
		}
		while (print.structwidth > 0)
		{
			ft_putchar_fd('0', 1);
			print.structwidth--;
		}
		ft_putstr_fd(print.str, 1);
	}
	else
	{
		if (print.str[0] == '-')
			print.structwidth--;
		while (print.structwidth > 0 && (print.structwidth + print.len) > *prec)
		{
			ft_putchar_fd(' ', 1);
			print.structwidth--;
		}
		if (print.str[0] == '-')
		{
			ft_putchar_fd('-', 1);
			print.str++;
		}
		while (*prec > print.len)
		{
			ft_putchar_fd('0', 1);
			*prec = *prec - 1;
		}
		ft_putstr_fd(print.str, 1);
	}
}

int	ft_subprintf(const char *s, va_list *list)
{
	int			i;
	int			j;
	int			k;
	int			width;
	char		*tmp;
	t_toprint	print;
	char		*tab;
	char		*(*tabfunct[7])(va_list*);
	int			index;
	int			prec;
	int l;

	i = 0;
	k = 0;
	l = 0;
	prec = 0;
	width = 0;
	tab = "csdiuxX";
	tabfunct[0] = &ft_printf_char;
   	tabfunct[1] = &ft_printf_str;
	tabfunct[2] = &ft_printf_int;
	tabfunct[3] = &ft_printf_int;
	tabfunct[4] = &ft_printf_unsigned;
	tabfunct[5] = &ft_printf_hexalow;
	tabfunct[6] = &ft_printf_hexaup;
	if (s[k] == '-' || s[k] == '0')
		k++;
	while (s[i + k] >= '0' && s[i + k] <= '9')
		i++;
	if (i)
	{
		tmp = malloc(sizeof(char) * (i + 1));
		if (!tmp)
			return (0);
		j = 0;
		while (j < i)
		{
			tmp[j] = s[j + k];
			j++;
		}
		tmp[j] = 0;
		width = ft_atoi(tmp);
		free (tmp);
	}
	if (s[i + k] == '.')
	{
		prec = 1;
		i++;
		if (s[i + k] == '*')
		{
			prec = va_arg(*list, int);
			l++;
		}
		else
		{
			while (s[i + k + l] > '0' && s[i + k + l] <= '9')
				l++;
			if (l)
			{
				tmp = malloc(sizeof(char) * (l + 1));
				if (!tmp)
					return (0);
				j = 0;
				while (j < l)
				{
					tmp[j] = s[j + i + k];
					j++;
				}
				tmp[j] = 0;
				prec = ft_atoi(tmp);
				free (tmp);
			}
		}
	}
	print.format = s[i + k + l];
	index = get_index(tab, print.format);
	print.str = (*tabfunct[index])(list);
	print.len = ft_strlen(print.str);
	if (print.str[0] == '-')
		print.len--;
	print.structwidth = width - print.len;
	ft_flags(print, &k, s, &prec);
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
