#include <stdio.h>


int main(void)
{
	int n;
	long long sum = 0;
	long long arr[81];
	scanf("%d", &n);

	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 2;


	for (int i = 4; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	
	if (n == 1)
		printf("4");
	else
		printf("%lld", arr[n] * 4 + arr[n - 1] * 2);

	return 0;
}