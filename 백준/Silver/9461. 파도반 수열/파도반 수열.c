#include <stdio.h>

int main(void) {

	int t, n;
	double a[103];
	scanf("%d", &t);
	a[0] = 1, a[1] = 1, a[2] = 1;

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		if (n < 3) {
			printf("1\n");
			continue;
		}

		for (int i = 3; i < n; i++)
			a[i] = a[i - 3] + a[i - 2];

		printf("%.lf\n", a[n - 1]);
	}

	return 0;
}