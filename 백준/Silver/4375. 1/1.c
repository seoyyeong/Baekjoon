#include <stdio.h>

int main(void) {
	int t, i, n = 0;
	while (scanf("%d", &n) != EOF) {
		i = 1;
		t = 1;
		while (1) {
			if (t % n == 0) {
				printf("%d\n", i);
				break;
			}
			else {
				t = ((t * 10) + 1) % n;
				i++;
			}
		}
	}
}