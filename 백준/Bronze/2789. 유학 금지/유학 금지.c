#include <stdio.h>

char check[10] = "CAMBRIDGE";

int main(void)
{
	int flag;
	char c;
	while (c = getchar())
	{
		if (c == '\n') return 0;
		flag = 0;
		for (int i = 0; i < 10; i++)
		{
			if (c == check[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0) printf("%c", c);
	}
}