#include <iostream>

long long arr[1000001];
long long cnt[10001];

int main(void)
{
	int n;
	int m;
	int temp;
	int mod;
	long long ans = 0;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &temp);
		arr[i] = arr[i - 1] + temp;
		mod = arr[i] % m;
		cnt[mod]++;
	}

	ans = cnt[0];

	for (int i = 0; i < m; i++)
	{
		if (cnt[i] > 0)
		{
			ans += cnt[i] * (cnt[i] - 1) / 2;
		}
	}
	printf("%lld\n", ans);

	return 0;
}