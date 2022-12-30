#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int n, k, cnt=0;
    int* a;
    scanf("%d%d", &n, &k);

    a = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    while (k != 0) {
        if (k >= a[--n]) {
            cnt += k / a[n];
            k %= a[n];
        }
    }

    printf("%d", cnt);
    free(a);

    return 0;
}