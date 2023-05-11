#include <stdio.h>

int main(void)
{
	int n;
	int t;
	int sum;
	scanf("%d", &n);
	scanf("%d", &sum);

	for (int i = 1; i < n; i++)
	{
		scanf("%d", &t);
		sum += t - 1;
	}

	printf("%d", sum);
	return 0;
}