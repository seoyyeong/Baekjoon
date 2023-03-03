#include <stdio.h>
#include <stdlib.h>
int dp[1001][1001];

int cmp(const int a, const int b) {
	if (a > b) return a;
	else return b;
}

int main(void) {
	
	int n, m, t, max = 0;
	int i, j;
	scanf("%d %d", &n, &m);

	if (n == 1 && m == 1) {
		scanf("%d", &t);
		printf("%d", t);
		return 0;
	}
	else if (n == 1 ){
		for (int i = 0; i < m; i++) {
			scanf("%d", &t);
			max += t;
		}
		printf("%d", max);
		return 0;
	}
	else if (m == 1) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &t);
			max += t;
		}
		printf("%d", max);
		return 0;

	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &dp[i][j]);
		}
	}

	for (i = 1; i < n; i++)
		dp[i][0] += dp[i - 1][0];
	
	for (i = 1; i < m; i++) 
		dp[0][i] += dp[0][i-1];
	
	for (i = 1; i < n; i++) {
		for (j = 1; j < m; j++) {
			t = dp[i][j];
			dp[i][j] += cmp(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			max = cmp(dp[i][j],max);
		}
	}
	printf("%d", max);

	return 0;
}