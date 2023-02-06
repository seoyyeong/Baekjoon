#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    char s[21];
    int l;
}data;

int main(void) {

    int t, n;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int max = 0, maxindex = 0;
        scanf("%d", &n);

        data* arr = (data*)malloc(sizeof(data) * n);
        for (int i = 0; i < n; i++) {
            scanf("%s %d", arr[i].s, &arr[i].l);
            if (max < arr[i].l) {
                max = arr[i].l;
                maxindex = i;
            }
        }
        printf("%s\n", arr[maxindex].s);
        free(arr);
    }

    return 0;
}