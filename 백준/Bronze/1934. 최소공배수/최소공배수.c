#include <stdio.h>

int gcd(int a, int b) {
	int t;
	while (a) {
		if (b == 0) break;
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main(void)
{
	int t;
	int a;
	int b;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", a * b / gcd(a, b));
	}

	return 0;
}