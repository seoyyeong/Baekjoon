#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) return 1;
	else return -1;
}

int main(void) {
	int n, l;
	int arr[1000];
	scanf("%d %d", &n, &l);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(int), cmp);

	for (int i = 0; i < n; i++) {
		if (l >= arr[i]) l++;
		else break;
	}

	printf("%d", l);
	return 0;
}