#include <stdio.h>
#include <stdlib.h>


int cmp(const long long a, const long long b) {
	if (a <= b) return a;
	else return b;
}

int main(void) {
	int n;
	long long min = 0;
	scanf("%d", &n);
	long long* len = (long long*)malloc(sizeof(long long) * n);
	long long* p = (long long*)malloc(sizeof(long long) * n);
	long long* dp = (long long*)malloc(sizeof(long long) * n);

	for (int i = 0; i < n - 1; i++) {
		scanf("%lld", &len[i]);
	}

	len[n - 1] = 0;
	scanf("%lld", &p[0]);
	dp[0] = len[0] * p[0];

	for (int i = 1; i < n; i++) {
		scanf("%lld", &p[i]);
		dp[i] = len[i] * p[i] + dp[i - 1];
	}


	min = dp[n - 1];

	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < i; j++) {
			if (p[j] < p[i])
				dp[i] = cmp(dp[i], dp[i - 1] + p[j] * len[i]);
			else
				dp[i] = cmp(dp[i], dp[i - 1] + p[i] * len[i]);
		}
		min = (min, dp[i]);
	}

	printf("%lld", min);
	free(len);
	free(p);
	free(dp);
	return 0;
}