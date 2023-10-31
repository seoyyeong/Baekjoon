#include <iostream>

enum FLAG { MINUS, PLUS };

int main(void)
{
	char c;
	int temp;
	int sum = 0;
	bool flag = PLUS;

	while (1)
	{
		scanf("%d", &temp);

		if (flag == MINUS)
			sum -= temp;

		else
			sum += temp;

		scanf("%c", &c);

		if (c == '\n')
			break;

		if (c == '-')
			flag = MINUS;
	}

	printf("%d", sum);

	return 0;
}