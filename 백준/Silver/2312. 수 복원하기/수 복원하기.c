#include <stdio.h>
#include <math.h>
#define MAX 100000

int main(void) {
	int tmp, check[MAX + 1] = { 0 };
	for (int i = 2; i <= sqrt(MAX); i++) {
		tmp = i * 2;
		while (tmp <= MAX) {
			check[tmp] = 1;
			tmp += 1;
		}
	}

	int t, n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int j = 2; j <= MAX; j++) {
			tmp = 0;
			while (n % j == 0) {
				tmp++;
				n /= j;
			}
			if (tmp != 0)
				printf("%d %d\n", j, tmp);
			if (n == 1) break;
		}
	}
	
	return 0;
}
