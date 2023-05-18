#include <stdio.h>
#include <math.h>


int main(void)
{
	int n;
	int i = 0;
	int t1;
	int t2;
	int cnt = 0;

	scanf("%d", &n);

	while (1)
	{
		t1 = pow(10, i);
		t2 = pow(10, i + 1);
		if (t2 > n)
		{
			cnt += (n - t1 + 1) * ++i;
			break;
		}
		cnt += (t2 - t1) * ++i;
	}


	printf("%d", cnt);

	return 0;
}