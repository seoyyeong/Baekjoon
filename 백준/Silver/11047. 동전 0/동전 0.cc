#include <iostream>

using namespace std;

int main(void)
{
	int n;
	int k;
	int cnt = 0;
	int arr[10];

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}


	for (int i = n - 1; i >= 0; i--)
	{
		int temp;

		temp = k / arr[i];
		k -= arr[i] * temp;
		cnt += temp;
	}

	printf("%d", cnt);

	return 0;
}