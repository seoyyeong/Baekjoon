#include <stdio.h>
#include <stdlib.h>


int main(void) {

    int n, sum;
    int *a, *b, *cnt;
    scanf("%d", &n);

    a = (int*)malloc(sizeof(int)*n);
    b = (int*)malloc(sizeof(int) * n);
    cnt = (int*)calloc(1001, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int max = a[0];

    for (int i = 0; i < n; i++) {
        if (a[i] > max)
            max = a[i];
        cnt[a[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        cnt[i] = cnt[i] + cnt[i-1];
    }

    for (int i = n - 1; i >= 0; i--) {
        b[--cnt[a[i]]] = a[i];
    }

    sum = b[0];

    for (int i = 1; i < n ; i++) {
        b[i]=b[i]+b[i-1];
        sum += b[i];
    }


    printf("%d", sum);

    free(a);
    free(b);
    free(cnt);

    return 0;
}