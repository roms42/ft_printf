/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:38:08 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/19 11:53:12 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int main()
{
	char *s = "lol";
	char c = '1';
	unsigned int n = 4294967291;
	int u = -5;
	int l = -8745;

	ft_printf(" Hello %d %8s %4c %-10.3i %03u %20.18x %-13X\n", n, s, c, n, u, u, u);
	printf(" Hello %d %8s %4c %-10.3i %03u %20.18x %-13X\n", n, s, c, n, u, u, u);
	ft_printf(" Hello %-10.*d yeh %20.18x\n", 10, l, u);
	printf(" Hello %-10.*d yeh %20.18x\n", 10, l, u);
	printf("%p\n", &c);
}