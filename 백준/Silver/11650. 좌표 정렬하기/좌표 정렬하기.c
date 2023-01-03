#include <stdio.h>
#include <stdlib.h>

int cmp(int a[2], int b[2]) {
    if (a[0] == b[0]) return a[1] - b[1];

    return a[0]-b[0];
}

int main(void) {

    int n;
    int arr[100000][2];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    qsort(arr, n, sizeof(int) * 2, cmp);

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i][0]);
        printf("%d\n", arr[i][1]);
    }

    return 0;
}