#include <stdio.h>

int main(void) {

    int n, v, cnt=0, arr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &v);

    for (int i = 0; i < n; i++)
        if (arr[i] == v) cnt++;

    printf("%d", cnt);

    return 0;

}