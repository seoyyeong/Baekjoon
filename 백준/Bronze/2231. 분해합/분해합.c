#include <stdio.h>

int main(void) {

    int n, gen;
    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        gen = i;
        int t = i;
        while (t!=0) {
            gen += t % 10;
            t /= 10;
        }
        if (gen == n) {
            printf("%d", i);
            return 0;
        }
    }
    printf("0");
    return 0;
}