#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b) {
	if (*(int*)a > *(int*)b) return 1;
	else return -1;
}

int main(void) {
	
	int arr[5], sum = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	sum /= 5;
	qsort(arr, 5, sizeof(int), cmp);
	printf("%d\n%d", sum, arr[2]);


	return 0;
}