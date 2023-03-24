#include <stdio.h>

int cmp(const int a, const int b) {
	if (a > b) return a;
	else return b;
}

int main(void) {
	int t, n;
	int dp[2][100000];

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &dp[i][j]);
			}
		}

		dp[0][1] += dp[1][0];
		dp[1][1] += dp[0][0];

		for (int i = 2; i < n; i++) {
			dp[0][i] += cmp(cmp(dp[0][i - 2], dp[1][i - 2]), dp[1][i - 1]);
			dp[1][i] += cmp(cmp(dp[0][i - 2], dp[1][i - 2]), dp[0][i - 1]);
		}
		printf("%d\n", cmp(dp[0][n - 1], dp[1][n - 1]));
	}
		
	return 0;
}