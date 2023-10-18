#include <iostream>

int arr[2000];

int cmp(const void* a, const void* b)
{
	return *(int*)a > *(int*)b;
}

int main(void)
{
	int n;
	int temp;
	int cnt = 0;
	int flag;
	int i;
	int j;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	qsort(arr, n, sizeof(int), cmp);
	temp = 0;

	while (temp < n)
	{
		i = 0;
		j = n - 1;
		flag = false;

		while (j > i)
		{

			if (arr[i] + arr[j] < arr[temp])
			{

				i++;
			}
			else if (arr[i] + arr[j] == arr[temp])
			{
				if (j == temp)
				{
					j--;
				}
				else if (i == temp)
				{
					i++;
				}
				else
				{
					flag = true;
					break;
				}
			}
			else
				j--;

		}
		cnt += flag;
		temp++;

	}

	printf("%d", cnt);

	return 0;
}