#include <stdio.h>

long long arr[1000001];

int main(void)
{
	int n;
	int t;
	long long sum = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		t = i;
		while (t <= n) {
			arr[t] += i;
			t += i;
		}
		sum += arr[i];
	}

	printf("%lld", sum);

	return 0;
}