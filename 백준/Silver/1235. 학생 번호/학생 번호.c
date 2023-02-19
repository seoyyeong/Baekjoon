#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m, len;

typedef struct data {
    char num[101];
}data;

int cmp(const void* a, const void* b) {
    data na = *(data*)a;
    data nb = *(data*)b;
    return strcmp(na.num+m, nb.num+m);
}

int check(data* a) {
    for (m = len - 1; m >= 0; m--) {
        qsort(a, n, sizeof(data), cmp);
        int flag = 0;
        for (int j = 0; j < n - 1; j++) {
            if (strcmp(a[j].num + m, a[j + 1].num + m) == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) return len - m;
    }
}

int main(void) {

    scanf("%d", &n);
    data* arr = (data*)malloc(sizeof(data) * n);

    for (int i = 0; i < n; i++)
        scanf("%s", arr[i].num);

    len = strlen(arr[0].num);

    printf("%d", check(arr));

    free(arr);
    return 0;
}

