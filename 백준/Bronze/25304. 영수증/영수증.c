#include <stdio.h>

int main(void) {

    int x, n, a, b, sum=0;

    scanf("%d%d", &x, &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        sum += a * b;
    }
    
    printf("%s", (sum == x) ? "Yes" : "No");
}