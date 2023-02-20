#include <stdio.h>
#include <stdlib.h>


int main(void) {

    int n, x, t;
    int max = 0, cnt = 0;
    scanf("%d %d", &n, &x);
    int* arr = (int*)malloc(sizeof(int) * n);

    scanf("%d", &arr[0]);
    for (int i = 1; i < n; i++) {
        scanf("%d", &t);
        arr[i] = arr[i - 1] + t;
    }

    for (int i = x - 1; i < n; i++) {
        int j = i - x;
        if (j < 0)
            t = arr[i];
        else t = arr[i] - arr[j];
        
        if (t > max) {
            max = t;
            cnt = 1;
        }
        else if (t == max) cnt++;
    }

    if (max == 0) printf("SAD");
    else printf("%d\n%d", max, cnt);

    free(arr);
    return 0;
}
