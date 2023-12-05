#include <iostream>

long long dp[90][2];

int main(void)
{
	int n;
	scanf("%d", &n);

	dp[0][1] = 1;
	dp[1][0] = 1;

	for (int i = 2; i < n; i++)
	{
		dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
		dp[i][1] = dp[i - 1][0];
	}

	printf("%lld", dp[n - 1][0] + dp[n - 1][1]);
	return 0;
}