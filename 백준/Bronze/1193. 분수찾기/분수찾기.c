#include <stdio.h>

int main(void) {

	int n, i = 1, j, k, cnt = 0;
	scanf("%d", &n);

	while (1) {
		int flag = 0;
		j = 0, k = 0;
		if (i % 2 == 0) {
			for (int a = 1; a <= i; a++) {
				j = a;
				k = i - a + 1;
				cnt++;
				if (cnt == n) {
					flag = 1;
					break;
				}
			}
		}
		else {
			for (int a = 1; a <= i; a++) {
				j = i - a + 1;
				k = a;
				cnt++;
				if (cnt == n) {
					flag = 1;
					break;
				}
			}
		}
		i++;
		if (flag == 1) break;
	}

	printf("%d/%d", j, k);
	return 0;
}