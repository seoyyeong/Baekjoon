#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int na = *(int*)a;
    int nb = *(int*)b;
    return nb - na;
}

int main(void) {

    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), cmp);

    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);

    free(arr);

    return 0;
}