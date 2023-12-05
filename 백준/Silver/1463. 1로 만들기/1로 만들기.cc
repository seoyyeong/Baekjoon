#include <iostream>
#define MIN(a,b) (a<b?a:b)

int dp[10'000'001];

int main(void)
{
	int x;
	scanf("%d", &x);

	for (int i = 2; i <= x; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0)
		{
			dp[i] = MIN(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			dp[i] = MIN(dp[i], dp[i / 3] + 1);
		}
	}

	printf("%d", dp[x]);

	return 0;
}