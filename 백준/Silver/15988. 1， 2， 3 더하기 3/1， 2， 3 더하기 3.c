#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001

int main(void) {
	int t, n;
	scanf("%d", &t);
	int* arr = (int*)malloc(sizeof(int) * MAX);

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 4; i < MAX; i++) {
		arr[i] = ((arr[i - 1] + arr[i - 2]) % 1000000009 + arr[i - 3]) % 1000000009;
	}

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%d\n", arr[n]);
	}

	free(arr);
	return 0;
}