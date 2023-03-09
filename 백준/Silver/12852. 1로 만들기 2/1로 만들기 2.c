#include <stdio.h>
#include <stdlib.h>

int cmp(const int a, const int b) {
	if (a < b) return a;
	else return b;
}

int main(void) {
	
	int n, t;
	scanf("%d", &n);
	if (n == 1) {
		printf("0\n1");
		return 0;
	}
	else if (n <= 3) {
		printf("1\n%d 1", n);
		return 0;
	}

	int* dp = (int*)calloc(n + 1, sizeof(int));
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		if (i % 3 == 0) {
			dp[i] = cmp(dp[i - 1] + 1, dp[i / 3] + 1);
			if (i % 2 == 0) {
				dp[i] = cmp(dp[i], dp[i / 2] + 1);
			}
		}
		else if (i % 2 == 0) 
			dp[i] = cmp(dp[i - 1] + 1, dp[i / 2] + 1);

		else 
			dp[i] = dp[i - 1] + 1;
	}

	printf("%d\n", dp[n]);
	
	while (n != 1) {
		printf("%d ", n);
		if (n % 3 == 0) {
			if (dp[n - 1] < dp[n / 3]) 
				t = 1;

			else t = 3;
			if (n % 2 == 0) {
				if (t == 1) {
					if (dp[n - 1] > dp[n / 2])
						t = 2;
				}
				else {
					if (dp[n / 3] > dp[n / 2])
						t = 2;
				}
			}
			if (t == 1) n--;
			else n /= t;
		}
		else if (n % 2 == 0) {
			if (dp[n - 1] < dp[n / 2]) n--;
			else n /= 2;
        }
		else 
			n--;

	}
	printf("1");
	free(dp);
	return 0;
}