#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	int na = *(int*)a;
	int nb = *(int*)b;
	return (na - nb)*(-1);
}

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	int* arr = (int*)malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	qsort(arr, n, sizeof(int), cmp);

	printf("%d", arr[k - 1]);
	free(arr);
	
	return 0;
} 