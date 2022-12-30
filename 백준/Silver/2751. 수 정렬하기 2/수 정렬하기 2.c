#include <stdio.h>
#include <stdlib.h>

int intcmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {

    int n;
    int *a;
    scanf("%d", &n);

    a = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), intcmp);

    for (int i = 0; i < n; i++)
        printf("%d\n", a[i]);
    
    free(a);
    
    return 0;
}