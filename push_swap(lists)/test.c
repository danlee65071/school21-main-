#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int is_in_set(int *arr, int n, int i)
{
	int j = -1;

	while (++j <= i)
	{
		if (arr[j] == n)
			return (1);
	}
	return (0);
}

int main()
{
	int i;
	int arr[1000];
	int n;
	int j = 0;

	srand(time(NULL));
	i = -1;
	while (++i < 500)
	{
		n = rand() % 500 - 250;
		if (!is_in_set(arr, n, i))
		{
			arr[j++] = n;
			printf("%d ", n);
		}
	}
	printf("\n%d\n", j);
}