#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int n, m;
    int* a, * b;
    scanf("%d%d", &n, &m);

    a = (int*)malloc(sizeof(int) * n * m);
    b = (int*)malloc(sizeof(int) * n * m);

    for (int i = 0; i < n * m; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n * m; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < n * m; i++) {
        printf("%d ", a[i] + b[i]);
        if ((i + 1) % m == 0) 
            printf("\n");
    }

    free(a);
    free(b);

    return 0;
}