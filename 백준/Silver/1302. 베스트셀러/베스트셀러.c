#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    char name[51];
}data;

int cmp(const void* a, const void* b) {
    data na = *(data*)a;
    data nb = *(data*)b;
    return strcmp(na.name, nb.name);
}


int main(void) {

    int n, cnt = 1, t = 1, maxindex = 0;
    scanf("%d", &n);
    data* arr = (data*)malloc(sizeof(data) * n);

    for (int i = 0; i < n; i++)
        scanf("%s", arr[i].name);

    qsort(arr, n, sizeof(data), cmp);

    for (int i = 1; i < n; i++) {
        if (strcmp(arr[i-1].name, arr[i].name) == 0)
            t++;
        else {
            if (cnt < t) {
                cnt = t;
                maxindex = i-1;
            }
            t = 1;
        }
    }

    if (cnt < t) printf("%s", arr[n - 1].name);
    else  printf("%s", arr[maxindex].name);
    return 0;
}