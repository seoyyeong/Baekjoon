#include <stdio.h>

int main(void) {

    int n, cnt = 0, i = 666;
    scanf("%d", &n);

    while (1) {
        int t = i;
        int s = 0, prev = 0;
        while (t>0) {
            prev = t % 10;
            t /= 10;
            if (prev == 6 && t % 10 == 6) s++;
            if (prev == 6 && t % 10 != 6 && s <= 1) s = 0;
            if (s >= 2) {
                cnt++;
                break;
            }
        }
        if (cnt == n) break;
        i++;
    }

    printf("%d", i);
    return 0;
}