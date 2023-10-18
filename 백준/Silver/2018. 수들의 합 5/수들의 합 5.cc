#include <iostream>


int main(void)
{
	int n;
	int m;
	int i;
	int j;
	int temp;
	int cnt = 0;
	
	scanf("%d", &n);

	m = n / 2 + 1;

	for (i = 1; i <= m; i++)
	{
		temp = i;

		for (j = i + 1;; j++)
		{
			temp += j;

			if (temp >= n)
			{
				if (temp == n)
				{
					cnt++;
				}
				break;
			}
		}
	}

	printf("%d", cnt + 1);
	return 0;
}