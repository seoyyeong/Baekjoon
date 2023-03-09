#include <stdio.h>

int main(void) {
	int n, cnt = 0;;
	int dp[1000][10] = { 0, };
	scanf("%d", &n);
	for (int i = 0; i < 10; i++) {
		dp[0][i] = 1;
	}

	for (int i = 1; i < n; i++) {
		dp[i][9] = 1;
		for (int j = 8; j >= 0; j--) {
			dp[i][j] += dp[i - 1][j] + dp[i][j + 1];
			dp[i][j] %= 10007;
		}
	}

	for (int i = 0; i < 10; i++) {
		cnt = ((cnt % 10007) + (dp[n - 1][i] % 10007)) % 10007;
	}

	printf("%d", cnt);
	return 0;
}