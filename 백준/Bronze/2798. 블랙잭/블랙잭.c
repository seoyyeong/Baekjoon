#include <stdio.h>

int main(void) {

    int n, m, ans, sum=0, diff=300000, arr[100] = { 0 };
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                sum = arr[i] + arr[j] + arr[k];
                if (m - sum >= 0 && m - sum <= diff) {
                    diff = m - sum;
                    ans = sum;
                }
            }
        }
    }

    printf("%d", ans);
    return 0;

}