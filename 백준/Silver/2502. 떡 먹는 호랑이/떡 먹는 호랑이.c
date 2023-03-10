#include <stdio.h>=

int main(void) {
	int d, k;
	int a, b;
	int dp[30];
	scanf("%d %d", &d, &k);

	for (a = 1; a < k; a++) {
		dp[0] = a;
		for (b = a; b < k; b++) {
			dp[1] = b;
			for (int c = 2; c < d; c++) {
				dp[c] = dp[c - 1] + dp[c - 2];
			}
			if (dp[d - 1] == k) {
				printf("%d\n%d", a, b);
				return 0;
			}
		}
	}

	return 0;
}