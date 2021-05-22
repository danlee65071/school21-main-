#include <stdio.h>

int ft_printf(char *fromat, ...);

int main()
{
	printf("%x ", 42);
	ft_printf(" %x", 42);
	return 0;
}
