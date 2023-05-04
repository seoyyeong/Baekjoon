#include <stdio.h>
#include <stdlib.h>

long long arr[100000];

int cmp(const void* a, const void* b)
{
	if (*(long long*)a > *(long long*)b) return 1;
	else if (*(long long*)a < *(long long*)b) return -1;
	else return 0;
}

int main(void)
{

	int n;
	int cnt = 1;
	int max = 1;
	long long ans;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);

	qsort(arr, n, sizeof(long long), cmp);

	ans = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] == arr[i - 1]) cnt++;
		else
		{
			if (max < cnt) {
				max = cnt;
				ans = arr[i - 1];
			}
			cnt = 1;
		}
	}

	if (max < cnt)
	{
		max = cnt;
		ans = arr[n - 1];
	}

	printf("%lld", ans);

	return 0;
}