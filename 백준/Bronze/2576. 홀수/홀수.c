#include <stdio.h>

int main(void) {

	int t, sum = 0, min = 101;

	for (int i = 0; i < 7; i++) {
		scanf("%d", &t);
		if (t % 2 != 0) {
			sum += t;
			if (t < min) min = t;
		}
	}

	if (sum == 0) printf("-1");
	else printf("%d\n%d", sum, min);
	return 0;
}
