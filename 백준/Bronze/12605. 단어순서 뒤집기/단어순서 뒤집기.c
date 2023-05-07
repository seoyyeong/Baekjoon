#include <stdio.h>


int main(void)
{
	int n;
	char c = '0';
	char s[5][26];

	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		int j = 0;
		int k = 0;
		while ((c = getchar()) != '\n')
		{
			if (c == ' ')
			{
				s[j][k] = '\0';
				j++;
				k = 0;
			}
			else
			{
				s[j][k++] = c;
			}
		}
		s[j][k] = '\0';

		printf("Case #%d: ", i);
		while (j >= 0)
		{
			printf("%s ", s[j--]);
		}
		printf("\n");
		
	}

	return 0;
}