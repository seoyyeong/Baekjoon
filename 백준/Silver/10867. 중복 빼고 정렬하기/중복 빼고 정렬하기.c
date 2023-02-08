#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int na = *(int*)a;
    int nb = *(int*)b;
    return na - nb;
}

int main(void) {

    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);

    printf("%d ", arr[0]);
    for (int i = 1; i < n; i++)
        if (arr[i] != arr[i - 1])
            printf("%d ", arr[i]);

    return 0;
}