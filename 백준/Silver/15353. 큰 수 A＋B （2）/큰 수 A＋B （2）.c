#include <stdio.h>
#include <string.h>

void add(char* a, char* b)
{
	int flag = 0;
	int len_a = strlen(a) - 1;
	int len_b = strlen(b) - 1;

	while (len_b >= 0)
	{
		flag = (a[len_a] - '0') + (b[len_b] - '0') + flag;
		if (flag >= 10) {
			a[len_a] = flag - 10 + '0';
			flag = 1;
		}
		else {
			a[len_a] = flag + '0';
			flag = 0;
		}
		len_b--;
		len_a--;
	}


	while (1)
	{
		if (len_a < 0)
		{
			if(flag != 0) printf("1");
			break;
		}
		flag = a[len_a] - '0' + flag;
		if (flag >= 10) {
			a[len_a] = flag - 10 + '0';
			flag = 1;
		}
		else {
			a[len_a] = flag + '0';
			flag = 0;
		} 
		len_a--;
	}
	printf("%s", a);
}

int main(void)
{
	char a[10001];
	char b[10001];

	scanf("%s %s", a, b);

	if (strlen(a) > strlen(b)) add(a, b);
	else add(b, a);

	return 0;
}
