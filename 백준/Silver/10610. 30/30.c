#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b)
{
	if (*(char*)a > *(char*)b) return -1;
	else return 1;
}

int main(void)
{
	char s[100001];
	int sum = 0;
	int flag1 = 0;
	int flag2 = 0;
	scanf("%s", s);

	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == '0') flag1 = 1;
		sum += s[i] - '0';
	}

	if (sum % 3 == 0) flag2 = 1;

	if (flag1 == 1 && flag2 == 1)
	{
		qsort(s, strlen(s), sizeof(char), cmp);
		printf("%s", s);
	}
	else printf("-1");

	return 0;
}