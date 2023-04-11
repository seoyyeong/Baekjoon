#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) return 1;
	else return -1;
}

int main(void) {
	int t, n, arr[50], max;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		max = 0;
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[j]);
		}
		qsort(arr, n, sizeof(int), cmp);

		for (int j = 0; j < n - 1; j++) {
			if (abs(arr[j] - arr[j + 1]) > max)
				max = abs(arr[j] - arr[j + 1]);
		}
		printf("Class %d\n", i);
		printf("Max %d, Min %d, Largest gap %d\n", arr[n - 1], arr[0], max);
	}
	

	return 0;
}