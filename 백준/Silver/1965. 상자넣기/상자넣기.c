#include <stdio.h>

int cmp(const int a, const int b) {
	if (a > b) return a;
	else return b;
}

int main(void) {
	
	int n, cnt = 0;
	int arr[1000];
	int dp[1000] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		dp[i]++;
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = cmp(dp[i], dp[j] + 1);
			}
		}
		cnt = cmp(cnt, dp[i]);
	}
	
	printf("%d", cnt);
	return 0;
}