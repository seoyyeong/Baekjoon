#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	int na = *(int*)a;
	int nb = *(int*)b;
	if (na < nb) return 1;
	else if (na == nb) return 0;
	else return -1;
}

int main(void) {

	int n;
	long long ans = 0;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	qsort(arr, n, sizeof(int), cmp);

	for (int i = 0; i < n; i++) {
		int t = arr[i] - i;
		if (t > 0)
			ans += t;
	}

	printf("%.0ld", ans);
	free(arr);
	return 0;
}