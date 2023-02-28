#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001

int main(void) {

	int tmp, p = 0;
	int* check = (int*)calloc(MAX, sizeof(int));
	for (int i = 2; i * i < MAX; i++) {
		tmp = i * 2;
		while (tmp < MAX) {
			check[tmp] = 1;
			tmp += i;
		}
	}

	int t, n, cnt;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);

		cnt = 0;
		for (int i = 2; i <= n / 2; i++) {
			if (check[i] == 0) {
				if (check[n - i] == 0) cnt++;
			}
			
		}
		printf("%d\n", cnt);
	}

	free(check);
	return 0;
}
