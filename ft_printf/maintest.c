/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:38:08 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/21 19:16:53 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int main()
{
	char *s = "hello";
	char c = '1';
	unsigned int n = 4294967291;
	int u = -5;
	int l = -8745;
	void *p;

	p = &c;
	ft_printf(" Hello %.3d %.7s %c %-5.3i %03u %20.18x %-13X\n", n, s, c, n, u, u, u);
	printf(" Hello %.3d %.7s %c %-5.3i %03u %20.18x %-13X\n", n, s, c, n, u, u, u);
	ft_printf(" Hello %-10.*d yeh %20.18x\n", 10, l, u);
	printf(" Hello %-10.*d yeh %20.18x\n", 10, l, u);
	ft_printf("%018p\n", p);
	printf("%018p\n", p);
}
