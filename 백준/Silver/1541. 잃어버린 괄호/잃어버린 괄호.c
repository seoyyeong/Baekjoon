#include <stdio.h>

int main(void) {
	int n, ans = 0;
	char c = '+';

	int i = 0, flag = 0; //0->+, 1->-
	while (1) {
		if (c == '\n') break;

		if (i % 2 == 0) {
			scanf("%d", &n);
			if (flag == 1)
				ans -= n;
			else
				ans += n;
		}
		else {
			scanf("%c", &c);

			if (flag == 0 && c == '-')
				flag = 1;
		}
		i++;
	}
	printf("%d", ans);

}