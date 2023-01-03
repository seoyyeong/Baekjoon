
#include <stdio.h>

int gcd(int a, int b) {
    int t;
    while (b) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main(void) {

    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n", gcd(a, b));
    printf("%d\n", lcm(a, b));

    return 0;
}