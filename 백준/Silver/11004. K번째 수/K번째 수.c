#include <stdio.h>
#include <stdlib.h>

int cmp(const int* a, const int* b) {
	return *(int*)a - *(int*)b;
}

int main(void) {
	
	int n, k;
	scanf("%d %d", &n, &k);
	k--;

	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	qsort(arr, n, sizeof(int), cmp);

	printf("%d", arr[k]);
    
    free(arr);

	return 0;
}