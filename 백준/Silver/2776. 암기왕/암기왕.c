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

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d", &a);
        int* arr = (int*)malloc(sizeof(int) * a);
        for (int j = 0; j < a; j++)
            scanf("%d", &arr[j]);
        qsort(arr, a, sizeof(int), cmp);

        scanf("%d", &b);
        for (int k = 0; k < b; k++) {
            int t, flag = 0;
            scanf("%d", &t);
            int mid, left = 0, right = a - 1;
            while (right >= left) {
                mid = (left + right) / 2;
                if (arr[mid] == t) {
                    flag = 1;
                    break;
                }
                else if (arr[mid] > t) right = mid - 1;
                else left = mid + 1;
            }
            printf("%d\n", flag);
        }
        free(arr);
    }

    return 0;
}
