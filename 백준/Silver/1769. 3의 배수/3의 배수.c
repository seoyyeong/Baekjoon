#include <stdio.h>
#include <string.h>

int main(void) {
	
	int y, cnt = 0;
	char x[1000001];
	scanf("%s", x);

	if (strlen(x) != 1) {
		while (1) {
			y = 0;
			for (int i = 0; i < strlen(x); i++) {
				y += x[i] - '0';
			}
			cnt++;
			if (y < 10) break;
			sprintf(x, "%d", y);
		}
	}
	else {
		y = x[0] - '0';
	}

	printf("%d\n%s", cnt, (y % 3 == 0) ? "YES" : "NO");

	return 0;
}