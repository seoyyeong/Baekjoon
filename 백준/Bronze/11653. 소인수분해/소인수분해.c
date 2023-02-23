#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i = 2;
    scanf("%d", &n);

    if (n == 1) return 0;

    while (n > 1) {
        while (n % i == 0) {
            printf("%d\n", i);
            n /= i;
        }
        i++;
    }
    return 0;
}