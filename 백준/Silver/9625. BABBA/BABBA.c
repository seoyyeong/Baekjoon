#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int k;
	long long arr[46];
	scanf("%d", &k);

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;

	for (int i = 3; i <= k; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	
	printf("%lld %lld", arr[k - 1], arr[k]);

	return 0;
}
