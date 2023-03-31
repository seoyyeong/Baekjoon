#include <stdio.h>
#define MOD 1000000000

int main(void) {
	
	int n, ans = 0;
	int dp[100][10] = { 0 };

	scanf("%d", &n);
	for (int i = 1; i < 10; i++) {
		dp[0][i]++;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 9)
				dp[i][j] = dp[i - 1][j - 1] % MOD;
			else if (j == 0)
				dp[i][j] = dp[i - 1][j + 1] % MOD;
			else 
				dp[i][j] = ((dp[i - 1][j - 1] % MOD) + (dp[i - 1][j + 1] % MOD)) % MOD;
		}
	}

	for (int i = 0; i < 10; i++) {
		ans += dp[n - 1][i];
		ans %= MOD;
	}
	printf("%d", ans);

	return 0;
}
