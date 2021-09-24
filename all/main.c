#include "printf.h"
#include <stdio.h>

int	main()
{
	ft_printf("hello dude %c %3s %010d %i %u %x %X %% %3p \n", 'W', "lol im back", -10, -99, -10, -99, -99, "999999");
	printf("hello dude %c %3s %010d %i %u %x %X %% %3p \n", 'W', "lol im back", -10, -99, -10, -99, -99, "999999");
}
