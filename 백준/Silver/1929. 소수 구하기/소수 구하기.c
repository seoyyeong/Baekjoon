#include <stdio.h>
#include <math.h>

int isPrime(int a) {

    if (a == 1) return 0;
    if (a < 3) return 1;
    for (int i = 2; i <= sqrt(a)+1; i++) {
        if (a % i == 0) return 0;
    }
    return 1;

}

int main(void) {

    int m, n;
    scanf("%d%d", &m, &n);

    for (int i = m; i <= n; i++)
        if (isPrime(i))
            printf("%d\n", i);

    return 0;
}