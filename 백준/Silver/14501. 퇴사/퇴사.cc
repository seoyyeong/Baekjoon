#include <iostream>
#define MAX(a,b) (a>b?a:b)

int dp[15];
int t[15];
int c[15];

int main(void)
{
	int n;
	int max = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &t[i], &c[i]);
		dp[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		if (i + t[i] <= n)
		{
			dp[i] = MAX(dp[i], c[i]);
			max = MAX(dp[i], max);
			for (int j = i + t[i]; j < n; j++)
			{
				if (j + t[j] <= n)
				{
					dp[j] = MAX(dp[j], dp[i] + c[j]);
					max = MAX(dp[j], max);
				}
			}
		}

	}


	printf("%d", max);

	return 0;
}