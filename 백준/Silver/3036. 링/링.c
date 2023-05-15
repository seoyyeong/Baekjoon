#include <stdio.h>

int gcd(int a, int b)
{
	int t;
	while (a)
	{
		if (b == 0) break;
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main(void)
{
	int n;
	int a;
	int b;
	int t;

	scanf("%d", &n);
	scanf("%d", &a);

	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d", &b);
		t = gcd(a, b);
		printf("%d/%d\n", a / t, b / t);
	}

	return 0;
}
