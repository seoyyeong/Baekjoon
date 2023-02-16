#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int na = *(int*)a;
    int nb = *(int*)b;
    if (na > nb) return 1;
    else if (na == nb) return 0;
    else return -1;
}

int main(void) {

    int n, q;
    scanf("%d %d", &n, &q);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);

    for (int i = 1; i < n; i++) 
        arr[i] += arr[i - 1];
    
    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        if (a == 0) printf("%d\n", arr[b]);
        else printf("%d\n", arr[b] - arr[a - 1]);
    }
    
    return 0;
}
