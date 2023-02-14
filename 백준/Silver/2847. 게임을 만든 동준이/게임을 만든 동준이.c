#include <stdio.h>

int main(void) {

    int n, arr[100], cnt = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = n - 1; i > 0; i--) {
        while (arr[i] <= arr[i - 1]) {
            arr[i - 1] -= 1;
            cnt++;
        }
    }

    printf("%d", cnt);
    return 0;
}