#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);

    if (len_a == len_b) return strcmp(a, b);
    return len_a-len_b;
}

int main(void) {

    int n;
    scanf("%d", &n);
    char *arr, *p;
    arr = (char*)malloc(sizeof(char) * n * 51);
    p = arr;
    for (int i = 0; i < n; i++) {
        scanf("%s", p);
        p += 51;
    }


    qsort(arr, n, 51, cmp);

    p = arr;

    for (int i = 0; i < n; i++) {
        if (strcmp(p,p+51)!=0) {
            printf("%s\n", p);
        }
        p += 51;
    }

    return 0;
}