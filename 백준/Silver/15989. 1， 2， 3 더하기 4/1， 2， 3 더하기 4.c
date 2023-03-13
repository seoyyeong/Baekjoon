#include <stdio.h>

int main(void) {
	int t, n;
	scanf("%d", &t);
	int dp[10001][3] = {0};
	dp[1][0] = 1;
	dp[1][1] = 0;
	dp[1][2] = 0;
	dp[2][0] = 1;
	dp[2][1] = 1;
	dp[2][2] = 0;
	dp[3][0] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;

	for (int i = 4; i <= 10000; i++) {
		dp[i][0] = 1;
		dp[i][1] = dp[i - 2][1] + 1;
		dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
	}
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%d\n", dp[n][0]+dp[n][1]+dp[n][2]);

	}
	return 0;
}