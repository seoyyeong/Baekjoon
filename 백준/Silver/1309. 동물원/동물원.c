#include <stdio.h>
#include <stdlib.h>
#define MOD 9901

int main(void) {
	int n;
	scanf("%d", &n);
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * 3);
	}

	arr[0][0] = 1;
	arr[0][1] = 1;
	arr[0][2] = 1;

	for (int i = 1; i < n; i++) {
		arr[i][0] = (arr[i - 1][0] + arr[i - 1][2] ) % MOD;
		arr[i][1] = (arr[i - 1][1] + arr[i - 1][2] ) % MOD;
		arr[i][2] = (arr[i - 1][0] + arr[i - 1][1]  + arr[i - 1][2])%MOD;

	}

	printf("%d", (arr[n - 1][0] + arr[n - 1][1] + arr[n - 1][2])%MOD);

	for (int i = 0; i < n; i++) {
		free(arr[i]);
	}

	free(arr);
	return 0;
}