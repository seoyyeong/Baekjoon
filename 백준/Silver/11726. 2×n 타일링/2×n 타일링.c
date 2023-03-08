#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int* dp = (int*)calloc(n + 1, sizeof(int));

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i < n + 1; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= 10007;
    }

    printf("%d", dp[n]);
    free(dp);
    return 0;
}