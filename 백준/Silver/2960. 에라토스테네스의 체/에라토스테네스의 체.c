#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, j, n, k, cnt = 0;
	scanf("%d %d", &n, &k);

	int *arr = (int*)calloc(n+1, sizeof(int));

	for (i = 2; i < n+1; i++) {
		j = 0;
		while ((j += i) <= n) {
			if (arr[j] == 1)
				continue;
			arr[j] = 1;
			cnt++;
			if (cnt == k) {
				printf("%d ", j);
				return 0;
			}
		}
	}
	return 0;

}