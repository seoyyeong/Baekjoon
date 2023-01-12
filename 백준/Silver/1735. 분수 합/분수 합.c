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

int main(void) {

	int an, ad, bn, bd;
	scanf("%d %d\n%d %d", &an, &ad, &bn, &bd);

	int a = ad, b = bd;
	ad *= b;
	an *= b;
	bd *= a;
	bn *= a;

	an += bn;

	int i = gcd(an, ad);
	an /= i;
	ad /= i;

	printf("%d %d", an, ad);

	return 0;
}