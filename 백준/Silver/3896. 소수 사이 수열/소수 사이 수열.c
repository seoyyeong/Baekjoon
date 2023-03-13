#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1299710

int main(void) {
	int t, k, cnt;
	int left, right;
	int* prime = (int*)calloc(MAX, sizeof(int));

	for (int i = 2; i < sqrt(MAX) ; i++) {
		t = i * 2;
		while (t < MAX) {
			prime[t] = 1;
			t += i;
		}
	}

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		cnt = 0;
		scanf("%d", &k);
		if (prime[k] != 0) {
			cnt = 1;
			left = k - 1;
			right = k + 1;
			while (prime[left] != 0) {
				left--;
				cnt++;
			}
			while (prime[right] != 0) {
				right++;
				cnt++;
			}
			cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}