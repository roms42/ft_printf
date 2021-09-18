/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:32:54 by rberthau          #+#    #+#             */
/*   Updated: 2021/09/18 12:49:04 by roms             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_getwidth(int *i, int *k, const char *s, va_list *list)
{
	int		j;
	char	*tmp;
	int		width;

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
	if (s[*k] == '*')
		width = va_arg(*list, int);
	free(tmp);
	return (width);
}

int	ft_getprec2(int *i, int *l, const char *s)
{
	char	*tmp;
	int		j;
	int		prec;

	prec = 1;
	j = 0;
	while (s[*i + *l] >= '0' && s[*i + *l] <= '9')
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
		free(tmp);
	}
	return (prec);
}

int	ft_getprecision(int *i, int *l, va_list *list, const char *s)
{
	int	prec;

	prec = 1;
	*i = *i + 1;
	if ((s[*i] < '0' || s[*i] > '9') && s[*i] != '*')
		prec = 0;
	else if (s[*i] == '*')
	{
		prec = va_arg(*list, int);
		*l = *l + 1;
	}
	else
		prec = ft_getprec2(i, l, s);
	return (prec);
}
