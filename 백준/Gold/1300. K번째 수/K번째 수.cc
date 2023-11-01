#include <iostream>

int main(void)
{
	int n;
	int k;

	scanf("%d %d", &n, &k);

	int left = 1;
	int right = k;
	int mid;
	int ans;

	while (right >= left)
	{
		int temp = 0;

		mid = (left + right) / 2;

		for (int i = 1; i <= n; i++)
		{
			if (mid / i > n)
				temp += n;
			else
				temp += mid / i;
		}

		if (temp >= k)
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	printf("%d", ans);

	return 0;
}