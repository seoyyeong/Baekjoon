#include <stdio.h>
#include <stdlib.h>

int cmp(const int a, const int b) {
	if (a > b) return a;
	else return b;
}

int main(void) {
	int n, max = 0;
	scanf("%d", &n);	
    if (n == 1) {
		printf("1");
		return 0;
	}
    
	int* arr = (int*)malloc(sizeof(int) * n);
	int* dp = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		dp[i]++;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				dp[i] = cmp(dp[i], dp[j] + 1);
		}
		max = cmp(max, dp[i]);
	}
	
	printf("%d", max);
	free(arr);
	free(dp);
	
	return 0;
}