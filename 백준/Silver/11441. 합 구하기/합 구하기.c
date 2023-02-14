#include <stdio.h>
#include <stdlib.h>


int main(void) {

    int n, m;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);

    scanf("%d", &arr[0]);

    for (int i = 1; i < n; i++) {
        int t;
        scanf("%d", &t);
        arr[i] = t + arr[i - 1];
    }

    scanf("%d", &m);
    for (int j = 0; j < m; j++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        if (a == 0) printf("%d\n", arr[b]);
        else printf("%d\n", arr[b] - arr[a - 1]);
    }

    free(arr);
    return 0;
}

