#include <stdio.h>

int main(void) {
    
	int t, n, m, a, cnt;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		cnt = 0;
		scanf("%d %d", &n, &m);
		if (n == 0) {
			n++;
			cnt++;
		}
		for (int j = n; j <= m; j++) {
			a = j;
			while (a > 0) {
				if (a % 10 == 0)
					cnt++;
				a /= 10;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}