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
	int n, min = 500000000;
	scanf("%d", &n);
	int n2 = n * 2;
	int* arr = (int*)malloc(sizeof(int) * n2);
	for (int i = 0; i < n2; i++) 
		scanf("%d", &arr[i]);
	
	qsort(arr, n2, sizeof(int), cmp);
	for (int i = 0; i < n; i++) {
		if (arr[i] + arr[n2 - 1 - i] < min) 
			min = arr[i] + arr[n2 - 1 - i];
	}
	printf("%d", min);
	free(arr);
	return 0;
}