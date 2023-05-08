#include <stdio.h>

int func(int n)
{
	int t;
	int cnt = 0;

	for (int i = 5; i <= n; i *= 5)
	{
		cnt += n / i;
	}

	return cnt;
}


int main(void)
{
	int t;
	int n;
	int cnt;
	scanf("%d", &t);


	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		cnt = func(n);
		printf("%d\n", cnt);
	}

	return 0;
}