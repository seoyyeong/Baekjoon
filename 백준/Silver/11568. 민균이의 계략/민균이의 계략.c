#include <stdio.h>
#include <stdlib.h>

int cmp(const int a, const int b) {
	if (a > b) return a;
	else return b;
}

int main(void) {
	
	int n, max = 1;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	int* dp = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = 1;
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = cmp(dp[i], dp[j] + 1);
			}
		}
		max = cmp(dp[i], max);
	}
	printf("%d", max);

	return 0;
}