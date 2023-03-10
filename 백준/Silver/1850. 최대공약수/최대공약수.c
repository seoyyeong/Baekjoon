#include <stdio.h>

long long gcd(long long a, long long b) {
	long long na = a;
	long long nb = b;
	long long c = na % nb;
	while (c != 0) {
		na = nb;
		nb = c;
		c = na % nb;
	}
	return nb;
}

int main(void) {
	long long a, b;
	scanf("%lld %lld", &a, &b);

	a = gcd(a, b);
	
	while (a--) {
		printf("1");
	}
	
	return 0;
}