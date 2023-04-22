#include <stdio.h>

int main(void)
{
	int n;
	int k;
	int i, j;
	int arr[20];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
    {
		scanf("%d", &arr[i]);
		getchar();
	}

	for (i = 0; i < k; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			arr[j] = arr[j + 1] - arr[j];
		}
	}


	for (i = 0; i < n - k - 1; i++)
		printf("%d,", arr[i]);

	printf("%d", arr[n - k - 1]);

	return 0;
}

