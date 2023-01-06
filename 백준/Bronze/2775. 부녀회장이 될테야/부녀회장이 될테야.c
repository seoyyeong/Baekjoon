#include <stdio.h>

int main(void) {

    int t, k, n, arr[14];

    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &k, &n);

        for (int i = 0; i < 14; i++)
            arr[i] = i + 1;

        for (int a = 0; a < k; a++) 
            for (int b = 0; b < n ; b++)
                arr[b + 1] += arr[b];

        printf("%d\n", arr[n-1]);
    }

    return 0;
}