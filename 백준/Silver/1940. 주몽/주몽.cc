#include <iostream>

int arr[15000];

int cmp(const void* a, const void* b)
{
	return *(int*)a > *(int*)b;
}

int main(void)
{
	int n;
	int m;
	int i;
	int j;
	int cnt = 0;

	scanf("%d\n%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(int), cmp);
	i = 0;
	j = n - 1;


	while (j > i)
	{

		if (arr[i] + arr[j] <= m)
		{
			if (arr[i] + arr[j] == m)
			{
				cnt++;
				j--;
			}
			else
			{
				i++;
			}
		}
		else
			j--;
	}

	printf("%d", cnt);

	return 0;
}