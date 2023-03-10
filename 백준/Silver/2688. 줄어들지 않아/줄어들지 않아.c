#include <stdio.h>

int main(void) {
	int t, n;
	long long sum;
	long long arr[64][10];
	scanf("%d", &t);

	for (int i = 0; i < 10; i++) {
		arr[0][i] = 1;
	}
	for (int i = 0; i < 64; i++) {
		arr[i][9] = 1;
	}

	for (int i = 1; i < 64; i++) {
		for (int j = 8; j >= 0; j--) {
			arr[i][j] = arr[i - 1][j] + arr[i][j + 1];
		}
	}

	for (int i = 0; i < t; i++) {
		sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < 10; i++) {
				sum += arr[n-1][i];
		}
		printf("%lld\n", sum);
	}

	return 0;
}