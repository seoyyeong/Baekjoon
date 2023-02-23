#include <stdio.h>

int main(void) {
	int n, a, b;
	int t = 1, cnt = 0;
	scanf("%d", &n);
	scanf("%d", &a);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &b);
		if (a + 1 == b) {
			a++;
			t++;
		}
		else if (a > b) {
			cnt++;
		}
		else{
			a = b;
			cnt += t;
			t = 1;
		}
	}
	printf("%d", cnt);
	return 0;
}