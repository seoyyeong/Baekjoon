#include <stdio.h>
#define MAX 50001

int cmp(const int a, const int b) {
	if (a < b) return a;
	else return b;
}

int main(void) {
	
	int n, maxsq = 1;
	int sq[MAX] = { 0 };
	int dp[MAX] = { 0, 1 };
	scanf("%d", &n);

	for (int i = 1; i * i < MAX; i++) {
		sq[i * i] = 1;
		dp[i * i] = 1;
	}
	
	if (sq[n] == 1) {
		printf("1");
		return 0;
	}

	for (int i = 2; i <= n; i++) {
		if (sq[i] == 1) continue;
		dp[i] = 4;
		for (int j = 1; j * j < i; j--) {
			dp[i] = cmp(dp[i], dp[i - j * j] + 1);
		}
	}

	printf("%d", dp[n]);

	return 0;
}