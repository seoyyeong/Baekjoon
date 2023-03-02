#include <stdio.h>
#include <stdlib.h>


int cmp(const int a, const int b) {
	if (a >= b) return a;
	else return b;
}

int main(void) {
	int n, max;
	scanf("%d", &n);


	int* arr = (int*)malloc(sizeof(int) * n);
	int* dp = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
	}

	max = dp[0];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				dp[i] = cmp(dp[i], dp[j] + arr[i]);
		}
		max = cmp(max, dp[i]);
	}
	
	printf("%d", max);
	free(arr);
	free(dp);
	
	return 0;
}