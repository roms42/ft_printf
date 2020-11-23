/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:38:08 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/23 17:00:14 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int main()
{
	char *s = "abc";
	char c = -0;
	unsigned int n = 4294967291;
	int u = -5;
	int l = -8745;
	void *p;
	int num = 0;

	p = &c;
	ft_printf(" Hello %d %s %4c %i %03u %20.18x %-13X\n", num, s, c, n, u, u, u);
	printf(" Hello %d %s %4c %i %03u %20.18x %-13X\n", num, s, c, n, u, u, u);
	ft_printf(" Hello %-10.*d yeh %20.18x\n", 10, l, u);
	printf(" Hello %-10.*d yeh %20.18x\n", 10, l, u);
	ft_printf("%18p\n", p);
	printf("%18p\n", p);
}
