#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b) {
	if (*(int*)a > *(int*)b) return 1;
	else return -1;
}

int main(void) {
	
	int arr[9], sum = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - (arr[i] + arr[j]) == 100) {
				arr[i] = 100;
				arr[j] = 100;
				qsort(arr, 9, sizeof(int), cmp);
				for (int k = 0; k < 7; k++) {
					printf("%d\n", arr[k]);
				}
				return 0;
			}
		}
	}
	return 0;
}

