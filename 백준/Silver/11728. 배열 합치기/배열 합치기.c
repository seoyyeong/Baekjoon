#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	int na = *(int*)a;
	int nb = *(int*)b;
	return (na - nb);
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	int nn = n + m;

	int* arr = (int*)malloc(sizeof(int) * nn);
	
	for (int i = 0; i < nn; i++)
		scanf("%d", &arr[i]);

	qsort(arr, nn, sizeof(int), cmp);


	for (int i = 0; i < nn; i++)
		printf("%d ", arr[i]);

	free(arr);
	
	return 0;
} 