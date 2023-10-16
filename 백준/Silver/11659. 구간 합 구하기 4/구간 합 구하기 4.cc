#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int arr[100001];

int main(void)
{
	int n;
	int m;
	int i;
	int j;
	int num;

	scanf("%d %d", &n, &m);

	for (int cnt = 1; cnt <= n; cnt++)
	{
		scanf("%d", &num);
		arr[cnt] = arr[cnt - 1] + num;
		
	}

	for (int cnt = 0; cnt < m; cnt++)
	{
		scanf("%d %d",&i, &j);
		printf("%d\n", arr[j] - arr[i - 1]);
	}

	return 0;
}