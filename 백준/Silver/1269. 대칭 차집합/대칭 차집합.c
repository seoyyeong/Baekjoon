#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int na = *(int*)a;
    int nb = *(int*)b;
    return na - nb;
}

int main(void) {

    int a, b;
    scanf("%d %d", &a, &b);

    int* arr1 = (int*)malloc(sizeof(int) * a);
    int* arr2 = (int*)malloc(sizeof(int) * b);

    for (int i = 0; i < a; i++)
        scanf("%d", &arr1[i]);

    for (int i = 0; i < b; i++)
        scanf("%d", &arr2[i]);

    qsort(arr1, a, sizeof(int), cmp);
    qsort(arr2, b, sizeof(int), cmp);

    int ta = a;
    int tb = b;

    for (int i = 0; i < a; i++) {
        int t = arr1[i];
        int mid, left = 0, right = b - 1;
        while (right >= left) {
            mid = (left + right) / 2;
            if (arr2[mid] == t) {
                tb--;
                break;
            }
            else if (arr2[mid] > t) right = mid - 1;
            else left = mid + 1;
        }
    }

    for (int i = 0; i < b; i++) {
        int t = arr2[i];
        int mid, left = 0, right = a - 1;
        while (right >= left) {
            mid = (left + right) / 2;
            if (arr1[mid] == t) {
                ta--;
                break;
            }
            else if (arr1[mid] > t) right = mid - 1;
            else left = mid + 1;
        }
    }

    printf("%d", ta + tb);

    free(arr1);
    free(arr2);
    return 0;
}