#include <stdio.h>

int main(void) {

    int arr[100][100] = { 0 };
    int n, a, b, cnt = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);

        for (int i = a; i < a + 10; i++) {
            for (int j = b; j < b + 10; j++) {
                if (!arr[i][j]) {
                    arr[i][j] = 1;
                    cnt++;
                }
            }
        }
    }
    printf("%d", cnt);
}