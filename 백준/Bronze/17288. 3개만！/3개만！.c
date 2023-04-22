#include <stdio.h>
#include <string.h>


int main(void)
{
	int n = 1;
	int cnt = 0;
	char s[101];
	scanf("%s", s);

	for (int i = 1; i < strlen(s); i++)
	{
		if (s[i] - 1 == s[i - 1])
		{
			n++;
			if (n == 3)
			{
				if (s[i] + 1 != s[i + 1]) {
					cnt++;
				}
				else {
					while (s[i]+1 == s[i+1]) i++;
					n = 0;
				}
			}
		}
		else {
			n = 1;
		}
	}
	
	printf("%d", cnt);
	return 0;
}