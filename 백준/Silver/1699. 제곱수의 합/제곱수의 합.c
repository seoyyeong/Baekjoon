#include <stdio.h>
#include <stdlib.h>

int cmp(const int a, const int b) {
	if (a < b) return a;
	else return b;
}

int main(void) {
	
	int n;
	scanf("%d", &n);
	int* dp = (int*)calloc(n + 1, sizeof(int));

	for (int i = 1; i * i <= n; i++)
		dp[i * i] = 1;

	for (int i = 2; i <= n; i++) {
		if (dp[i] == 0) dp[i] = i;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = cmp(dp[i], dp[i - j * j] + 1);
		}
	}
	
	printf("%d", dp[n]);
	free(dp);
	return 0;
}