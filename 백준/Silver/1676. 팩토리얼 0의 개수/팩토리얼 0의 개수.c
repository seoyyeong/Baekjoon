#include <stdio.h>

int main(void) {
	int n, t, cnt;
	scanf("%d", &n);
	cnt = 0;
	for (int i = 0; i <= n; i++) {
		t = i;
		while (t > 0) {
			if (t % 5 == 0) {
				cnt++;
				t /= 5;
			}
			else break;
		}
	}

	printf("%d", cnt);
}
