#include <stdio.h>

int gcd(int a, int b)
{
	int temp;
	while (b > 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main(void)
{	
	int n;
	int m;
	int g;
	scanf("%d:%d", &n, &m);

	g = gcd(n, m);

	printf("%d:%d", n / g, m / g);

	return 0;
}
