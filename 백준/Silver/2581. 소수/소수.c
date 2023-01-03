#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if (n == 1) return 0;
    else if (n <= 3) return 1;
    else {
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return 0;
    }
    return 1;
}

int main(void) {

    int m, n, min, sum = 0;
    scanf("%d %d", &m, &n);

    for (int i = m; i <= n; i++) {
        if (isPrime(i)) sum+=i;
    }
    
    if (sum == 0) {
        printf("-1");
        return 0;
    }
    else {
        printf("%d\n", sum);
        for (int i = m; i <= n; i++) {
            if (isPrime(i)) {
                min = i;
                break;
            }
        }
        printf("%d", min);
    }

    return 0;
}