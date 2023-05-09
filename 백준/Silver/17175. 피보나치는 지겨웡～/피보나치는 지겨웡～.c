#include <stdio.h>

int main(void)
{
	long long n;
	long long dp[51];
	scanf("%lld", &n);

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = (1 + dp[i - 2] + dp[i - 1]) % 1000000007;
	}

	printf("%lld", dp[n]);
	return 0;
}