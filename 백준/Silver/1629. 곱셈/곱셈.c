#include <stdio.h>

int main(void)
{
	long long a;
	long long b;
	long long c;
	long long ans = 1;

	scanf("%lld %lld %lld", &a, &b, &c);

	while (b > 0)
	{
		if (b % 2 == 1)
			ans = (ans * a) % c;
		a = a % c * a % c % c;
		b /= 2;
	}

	printf("%d", ans);
	return 0;
}