#include <stdio.h>
#include <stdarg.h>

int ft_printf(char *format, ...);

int main()
{
	printf("%5.1s", "hi");
	printf("\n");
	ft_printf("%5.1s", "hi");
	return 0;
}
