/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <rberthau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:38:08 by rberthau          #+#    #+#             */
/*   Updated: 2020/11/25 21:27:17 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int main()
{
	/*char *s = "abc";
	char f = '2';
	unsigned int n = 4294967291;
	int u = -5;
	int z = -8745;
	void *p;
	int num = 0;
	int a;
	int b;

	p = &f;
	a = ft_printf(" Hello %d\n", n);
	b = printf(" Hello %d\n", n);
	printf("%d %d \n", a, b);
	ft_printf(" Hello %-10.*d yeh %20.18x\n", 10, z, u);
	printf(" Hello %-10.*d yeh %20.18x\n", 10, z, u);
	ft_printf("%18p\n", p);
	printf("%18p\n", p);
	printf("%d\n", printf("%5s", "goes over"));
	ft_printf("%d\n", ft_printf("%5s", "goes over"));
	printf("%d\n", printf("basic 0 : %d\n", num));
	ft_printf("%d\n", ft_printf("basic 0 : %d\n", num));
	printf("%d\n", printf("%0.5i\n", 2));
	ft_printf("%d\n", ft_printf("%0.5i\n", 2));
	printf("%d\n", printf("%.6i\n", -3));
	ft_printf("%d\n", ft_printf("%.6i\n", -3));
	printf("%d\n", printf("%5.0i\n", 0));
	ft_printf("%d\n", ft_printf("%5.0i\n", 0));
	printf("%d\n", printf("%.0i\n", 0));
	ft_printf("%d\n", ft_printf("%.0i\n", 0));
	printf("%d\n", printf("%7i\n", -14));
	ft_printf("%d\n", ft_printf("%7i\n", -14));
	printf("%.d\n", printf("%.3s\n", "hello"));
	ft_printf("%.d\n", ft_printf("%.3s\n", "hello"));
	printf("%.d\n", printf("%-4i\n", 94827));
	ft_printf("%.d\n", ft_printf("%-4i\n", 94827));
	printf("%.d\n", printf("%.4i\n", -2372));
	ft_printf("%.d\n", ft_printf("%.4i\n", -2372));
	printf("%.d\n", printf("%.3i\n", 13862));
	ft_printf("%.d\n", ft_printf("%.3i\n", 13862));
	printf("%.d\n", printf("%10.5i\n", -216));
	ft_printf("%.d\n", ft_printf("%10.5i\n", -216));
	printf("%.d\n", printf("%8.3i\n", -8473));
	ft_printf("%.d\n", ft_printf("%8.3i\n", -8473));
	}
	printf("%.d\n", printf("%3.3i\n", -8462));
	ft_printf("%.d\n", ft_printf("%3.3i\n", -8462));
	printf("%.d\n", printf("%-10.5i\n", -216));
	ft_printf("%.d\n", ft_printf("%-10.5i\n", -216));
	printf("%.d\n", printf("%p\n", NULL));
	ft_printf("%.d\n", ft_printf("%p\n", NULL));
	printf("%d\n", printf("%18p\n", p));
	ft_printf("%d\n", ft_printf("%18p\n", p));
	printf("%d\n", printf("%2p\n", NULL));
	ft_printf("%d\n", ft_printf("%2p\n", NULL));
	printf("%d\n", printf("%.p\n", NULL));
	ft_printf("%d\n", ft_printf("%.p\n", NULL));
	printf("%d\n", printf("%5.p\n", NULL));
	ft_printf("%d\n", ft_printf("%5.p\n", NULL));
	printf("%d\n", printf("%2.9p\n", 1234));
	ft_printf("%d\n", ft_printf("%2.9p\n", 1234));


printf("%d\n", printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~',''));
ft_printf("%d\n", ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~',''));

	printf("%d\n", printf("%  d\n", -42));
	ft_printf("%d\n", ft_printf("%  d\n", -42));

	printf("%d\n", printf("%%d 0000042 == |%d|\n", 0000042));
	ft_printf("%d\n", ft_printf("%%d 0000042 == |%d|\n", 0000042));

	printf("%d\n", printf("%%d \t == |%d|\n", '\t'));
	ft_printf("%d\n", ft_printf("%%d \t == |%d|\n", '\t'));

	printf("%d\n", printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e'));
	ft_printf("%d\n", ft_printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e'));

	printf("%d\n", printf("%*s\n", -32, "abc"));
	ft_printf("%d\n", ft_printf("%*s\n", -32, "abc"));

	printf("%d\n", printf("%*i\n", -14, 94827));
	ft_printf("%d\n", ft_printf("%*i\n", -14, 94827));

	printf("%d\n", printf("%*s\n", -3, "hello"));
	ft_printf("%d\n", ft_printf("%*s\n", -3, "hello"));

	printf("%d\n", printf("%.*i\n", -6, -3));
	ft_printf("%d\n", ft_printf("%.*i\n", -6, -3));

	printf("%d\n", printf("%010%"));
	ft_printf("%d\n", ft_printf("%010%"));


	printf("%d\n", printf("%%"));
	ft_printf("%d\n", ft_printf("%%"));*/

    int		a = -1;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
	
	
	ft_printf(" --- Return : %d\n", ft_printf("%0.i, %0.d", i, j)); //T12
	printf(" --- Return : %d\n", printf("%0.i, %0.d", i, j)); //T12
	printf("heelo, %d \n", 54);
	ft_printf("heelo, %d \n", 54);


	a = 4;
	b = -2;
	while (b < 5)
	{
		printf("b = %d\n", b);
		printf(" --- Return : %d\n", printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
		ft_printf(" --- Return : %d\n", ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));

		printf(" --- Return : %d\n", printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
		ft_printf(" --- Return : %d\n", ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));

		printf(" --- Return : %d\n", printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
		ft_printf(" --- Return : %d\n", ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
		b++;
	}

	printf("%d\n", printf("%-1.0d", 0));
	ft_printf("%d\n", ft_printf("%-1.0d", 0));
	
	printf("%d\n", printf("%*.*d",-1, 0, 0));
	ft_printf("%d\n", ft_printf("%*.*d", -1, 0, 0));

	printf("%d\n", printf("%0*.*i\n",a, b, i));
	ft_printf("%d\n", ft_printf("%0*.*i\n", a, b, i));

	printf(" --- Return : %d\n", printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d));
	ft_printf(" --- Return : %d\n", ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d)); 


	printf("%d\n", printf("%03i", 0));
	ft_printf("%d\n", ft_printf("%03i", 0));



	a = -4;
	int z = 187;
	while (a < 5)
	{
		printf("%d\n", z);
		printf(" --- Return : %d\n", printf("%*s, %*s, %*s, %*s, %*s, %*s, %*s, %*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
		ft_printf(" --- Return : %d\n", ft_printf("%*s, %*s, %*s, %*s, %*s, %*s, %*s, %*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
		

		printf(" --- Return : %d\n", printf("%-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
		ft_printf(" --- Return : %d\n", ft_printf("%-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));

		printf(" --- Return : %d\n", printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
		ft_printf(" --- Return : %d\n", ft_printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
		a++;
		z = z + 3;
	}

	printf(" --- Return : %d\n", printf("%1.s, %1.s, %1.s, %1.s, %1.s", n, o, p, q, r));
	ft_printf(" --- Return : %d\n", ft_printf("%1.s, %1.s, %1.s, %1.s, %1.s", n, o, p, q, r));

	a = -4;
	while(a < 5) //T70-177
	{
		printf("\n\na = %d\n", a);
		b = -2;
		while (b < 5)
		{
			printf("\n\nb = %d\n", b);
			printf(" --- Return : %d\n", printf("%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
			ft_printf(" --- Return : %d\n", ft_printf("%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));


			printf(" --- Return : %d\n", printf("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
			ft_printf(" --- Return : %d\n", ft_printf("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
			b++;
		}
		a++;
	}
	
	printf(" --- return = %d\n", printf("%*.*d", -19, 2, -42));
	ft_printf(" --- return = %d\n", ft_printf("%*.*d", -19, 2, -42));
	
	
	printf(" --- Return : %d\n", printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i));
	ft_printf(" --- Return : %d\n", ft_printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i));



/*
	printf(" --- Return : %d\n", printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i));
	printf(" --- Return : %d\n", printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j));
	printf(" --- Return : %d\n", printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, l, a, l, a, l, a, l, a, l));
	printf(" --- Return : %d\n", printf("%i, %d, %d, %d, %d, %d, %u, %x, %X", 0, 0, 0, 0, 0, 0, 0, 0, 0));
	printf(" --- Return : %d\n", printf("%*i, %*d, %*d, %*d, %*d, %*d, %*u, %*x, %*X", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0));
	printf(" --- Return : %d\n", printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
	printf(" --- Return : %d\n", printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
	// ^ Theoriquement un comportement indefini mais testé par la moulinette
    printf(" --- Return : %d\n", printf("(null)"));
	printf(" --- Return : %d\n", printf(""));
*/
}
