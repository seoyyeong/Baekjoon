#include <stdio.h>

int main(void) {
    
    int a = 1, b, c;
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0) break;

        if (a > b && a > c)
            printf("%s\n", (b * b + c * c == a * a) ? "right" : "wrong");
        else if (b > a && b > c)
            printf("%s\n", (a * a + c * c == b * b) ? "right" : "wrong");
        else
            printf("%s\n", (a * a + b * b == c * c) ? "right" : "wrong");
    }

    return 0;
}