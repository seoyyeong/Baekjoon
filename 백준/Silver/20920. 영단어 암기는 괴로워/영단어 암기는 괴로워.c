#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    char s[11];
    int cnt;
}data;

int cmp1(const void* a, const void* b) {
    data na = *(data*)a;
    data nb = *(data*)b;
    return strcmp(na.s, nb.s);
}

int cmp2(const void* a, const void* b) {
    data na = *(data*)a;
    data nb = *(data*)b;
    
    if (na.cnt < nb.cnt) return 1;
    else if (na.cnt > nb.cnt) return -1;
    if (strlen(na.s) < strlen(nb.s)) return 1;
    else if (strlen(na.s) > strlen(nb.s))return -1;
    else return strcmp(na.s, nb.s);
}

int main(void) {

    int n, m;
    scanf("%d %d", &n, &m);
    char t[11];
    data* arr1 = (data*)malloc(sizeof(data) * n);

    int i = 0;
    while (n != 0) {
        scanf("%s", &t);
        if (strlen(t) >= m)
            strcpy(arr1[i++].s, t);
        n--;
    }

    qsort(arr1, i, sizeof(data), cmp1);

    data* arr2 = (data*)malloc(sizeof(data) * i);

    int c = 0;
    strcpy(arr2[c].s, arr1[c].s);
    arr2[c].cnt = 1;
    for (int j = 1; j < i; j++) {
        if (strcmp(arr1[j].s, arr2[c].s) == 0) {
            arr2[c].cnt++;
        }
        else {
            strcpy(arr2[++c].s, arr1[j].s);
            arr2[c].cnt = 1;
        }
    }
    c++;
    qsort(arr2, c, sizeof(data), cmp2);

    for (int k = 0; k < c; k++)
        printf("%s\n", arr2[k].s);

    free(arr1);
    free(arr2);
    return 0;
}
