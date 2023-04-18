#include <stdio.h>


int main(void)
{	
	int n;
	long long arr[117];
	scanf("%d", &n);

	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;

	for (int i = 4; i < n + 1; i++) {
		arr[i] = arr[i - 1] + arr[i - 3];
	}

	printf("%lld", arr[n]);

	return 0;
}
