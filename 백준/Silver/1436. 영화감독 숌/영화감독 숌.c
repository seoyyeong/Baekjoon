#include <stdio.h>

int main(void) {

    int n, cnt = 0, i = 666;
    scanf("%d", &n);

    while (1) {
        int t = i;
        while (t > 0) {
            if (t % 1000 == 666) {
                cnt++;
                break;
            }
            t /= 10;
        }
        if (cnt == n) break;
        i++;
    }

    printf("%d", i);
    return 0;
}