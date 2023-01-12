#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	return *(int*)a > *(int*)b;
}

int main(void) {

	int n, max = 0;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	qsort(arr, n, sizeof(int), cmp);

	for (int i = 0; i < n; i++) {
		int t = arr[i] * (n - i);
		if (max < t) max = t;
	}

	printf("%d", max);

	return 0;
}