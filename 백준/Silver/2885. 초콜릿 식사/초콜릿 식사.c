#include <stdio.h>


int main(void) {
	int k, i, tmp = 0, cnt = 0;
	scanf("%d", &k);

	i = 1;
	while (i < k) 
		i *= 2;

	printf("%d ", i);
	if (i == k) {
		printf("0");
		return 0;
	}

	while (tmp!=k) {
		i /= 2;
		cnt++;
		if (tmp + i <= k) {
			tmp += i;
		}
	}

	printf("%d", cnt);
	return 0;
}
