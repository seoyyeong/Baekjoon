#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int n, k, flag, cnt = 0, i = 0, j = 0;
    scanf("%d %d", &n, &k);
    int* arr = (int*)malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++)
        *(arr + i) = i + 1;

    printf("<");

    while (1) {
        if (*(arr + i % n) != 0) {
            j++;
            flag = 1;
        }
        else flag = 0;

        if (j % k == 0 && flag == 1) {
            printf("%d", *(arr + i % n));
            cnt++;
            *(arr + i % n) = 0;
            if (cnt == n) break;
            printf(", ");
        }
        i++;
    }
    printf(">");

    free(arr);

    return 0;
}