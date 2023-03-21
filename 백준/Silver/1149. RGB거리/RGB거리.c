#include <stdio.h>
#include <stdlib.h>

int cmp(const int a, const int b) {
	if (a < b) return a;
	else return b;
}

int main(void) {
	
	int n, min,  dp[1000][3] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &dp[i][0], &dp[i][1], &dp[i][2]);
	}

	for (int i = 1; i < n; i++) {
			dp[i][0] += cmp(dp[i-1][1], dp[i-1][2]);
			dp[i][1] += cmp(dp[i-1][0], dp[i-1][2]);
			dp[i][2] += cmp(dp[i-1][0], dp[i-1][1]);
	}

	min = cmp(cmp(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
	printf("%d", min);

	return 0;
}