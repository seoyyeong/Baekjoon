#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	int na = *(int*)a;
	int nb = *(int*)b;
	if (na > nb) return 1;
	else if (na == nb) return 0;
	else return -1;
}

int main(void) {
	
	int n, mid, f, fidx, range;
	double avg = 0;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	int check[8001] = { 0 };

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		avg += arr[i];
		check[arr[i] + 4000]++;
	}

	qsort(arr, n, sizeof(int), cmp);

	avg /= n;
	if (avg <= 0 && avg > -0.5)
		avg = 0;
	mid = arr[n / 2];
	f = 0;
	range = arr[n - 1] - arr[0];

	for (int i = 0; i < 8001; i++) {
		if (f < check[i]) {
			f = check[i];
			fidx = i;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 8001; i++) {
		if (f == check[i]) {
			fidx = i;
			cnt++;
		}
		if (cnt == 2)
			break;
	}

	printf("%.0f\n", avg);
	printf("%d\n", mid);
	printf("%d\n", fidx - 4000);
	printf("%d", range);
	free(arr);
	return 0;
}
