#include <stdio.h>


int main(void)
{
	unsigned int s;
	unsigned int n = 1;
	scanf("%d", &s);

	while (1)
	{
		if (s >= n)
		{
			s -= n;
			n++;
		}
		else break;
	}
	n--;

	printf("%d", n);
	return 0;
}
